#!/bin/bash
gcc -wall -wextra -werror -pedantic -c -FPLC *.c
gcc -shared -o liball.so *.o
export LD_LIBRARY_PATH=.:$LD_LIBARY_PATH
