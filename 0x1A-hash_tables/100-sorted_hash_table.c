#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * shash_table_create - Create a sorted hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created sorted hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    for (unsigned long int i = 0; i < size; i++)
        ht->array[i] = NULL;

    ht->shead = NULL;
    ht->stail = NULL;

    return (ht);
}

/**
 * shash_table_set - Insert a key/value pair into a sorted hash table
 * @ht: The sorted hash table
 * @key: The key to insert
 * @value: The value to associate with the key
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    if (ht == NULL || key == NULL || value == NULL)
        return (0);

    unsigned long int index = key_index((const unsigned char *)key, ht->size);
    shash_node_t *new_node, *current, *prev = NULL;

    current = ht->array[index];
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            free(current->value);
            current->value = strdup(value);
            return (1);
        }
        prev = current;
        current = current->next;
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return (0);
    }
    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return (0);
    }

    if (prev == NULL)
    {
        ht->array[index] = new_node;
        new_node->next = NULL;
    }
    else
    {
        prev->next = new_node;
        new_node->next = current;
    }

    /* Insert into sorted linked list */
    if (ht->shead == NULL || strcmp(ht->shead->key, key) > 0)
    {
        new_node->snext = ht->shead;
        ht->shead = new_node;
    }
    else
    {
        shash_node_t *tmp = ht->shead;
        while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
            tmp = tmp->snext;
        new_node->snext = tmp->snext;
        tmp->snext = new_node;
    }

    if (new_node->snext == NULL)
        ht->stail = new_node;

    return (1);
}

/**
 * shash_table_get - Retrieve a value associated with a key in a sorted hash table
 * @ht: The sorted hash table
 * @key: The key to look up
 *
 * Return: The value associated with the key, or NULL if the key is not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    if (ht == NULL || key == NULL)
        return (NULL);

    unsigned long int index = key_index((const unsigned char *)key, ht->size);
    shash_node_t *current = ht->array[index];

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
            return (current->value);
        current = current->next;
    }

    return (NULL);
}

/**
 * shash_table_print - Print the sorted hash table using the sorted linked list
 * @ht: The sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *current = ht->shead;

    printf("{");
    while (current != NULL)
    {
        printf("'%s': '%s'", current->key, current->value);
        if (current->snext != NULL)
            printf(", ");
        current = current->snext;
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Print the sorted hash table in reverse order
 * @ht: The sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *current = ht->stail;

    printf("{");
    while (current != NULL)
    {
        printf("'%s': '%s'", current->key, current->value);
        if (current->sprev != NULL)
            printf(", ");
        current = current->sprev;
    }
    printf("}\n");
}

/**
 * shash_table_delete - Delete a sorted hash table and its elements
 * @ht: The sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
    if (ht == NULL)
        return;

    for (unsigned long int i = 0; i < ht->size; i++)
    {
        shash_node_t *current = ht->array[i];
        while (current != NULL)
        {
            shash_node_t *temp = current;
            current = current->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }

    free(ht->array);
    free(ht);
}

