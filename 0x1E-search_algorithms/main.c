#include <stdio.h>
#include "search_algos.h"

int main(void) {
    int array[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(array) / sizeof(array[0]);
    int value_to_search = 3;

    int result = linear_search(array, size, value_to_search);

    if (result != -1) {
        printf("Value %d found at index %d\n", value_to_search, result);
    } else {
        printf("Value %d not found in the array\n", value_to_search);
    }

    return 0;
}

