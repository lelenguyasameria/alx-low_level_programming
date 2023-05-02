#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head node of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
const listint_t *slow, *fast;
size_t count = 0;
if (!head)
exit(98);
slow = head;
fast = head;
while (slow && fast && fast->next)
{
slow = slow->next;
fast = fast->next->next;
if (slow == fast)
{
printf("-> [%p] %d\n", (void *)slow, slow->n);
exit(98);
}
printf("[%p] %d\n", (void *)slow, slow->n);
count++;
}
printf("[%p] %d\n", (void *)slow, slow->n);
count++;
return (count);
}
