#!/bin/sh
echo "\033[0;32m=== RUNNER ===\033[0m"
# gcc -Wall -Wextra -Werror $1.c utils/*.c -I ./includes -o $1.out
gcc $1.c utils/*.c -I ./includes -o $1.out
valgrind -q --leak-check=full --track-origins=yes ./$1.out $2 $3