#!/bin/bash
# Compila com printf
	gcc -g -Wall -Wextra -fsanitize=address -D PRINT=printf -o main main.c ./libft/libft.a ./libftprintf/libftprintf.a
	./main > pads

# Compila com ft_printf
	gcc -g -Wall -Wextra -fsanitize=address -D PRINT=ft_printf -o main main.c ./libft/libft.a ./libftprintf/libftprintf.a
	./main > padt

diff -y --suppress-common-lines pads padt > dif

vim dif
