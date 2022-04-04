#!/bin/sh
gcc -Werror -Wextra -Wall $1.c -o $1 && ./$1 $2 $3