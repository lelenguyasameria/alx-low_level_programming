#ifndef DOG_H
#define DOG_H

/* The contents of your header file go here */

int _putchar(char c);

/* Definition of the struct dog */
struct dog {
    char *name;
    float age;
    char *owner;
};

/* Typedef for struct dog */
typedef struct dog dog_t;

/* Function prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif /* DOG_H */

