#ifndef DOG_H
#define DOG_H
#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
Prototype: void init_dog(struct dog *d, char *name, float age, char *owner);
Prototype: void print_dog(struct dog *d);
Prototype: dog_t *new_dog(char *name, float age, char *owner);
Prototype: void free_dog(dog_t *d);

#endif
