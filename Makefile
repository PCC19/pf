.PRECIOUS: main
main:	main.c lib 
	clear;
	gcc -g -Wall -Wextra -fsanitize=address -o main main.c ./libft/libft.a ./libftprintf/libftprintf.a
	#gcc -g -Wall -Wextra -Werror -o main main.c ./libft/libft.a ./libftprintf/libftprintf.a
	./main

lib:
	echo MAIN
#	rm -f ./libft/libft.a
#	rm -f ./libftprintf/libftprintf.a
	make -C ./libftprintf

all:	main lib

re:
	make -C ./libftprintf re
	make all

val:	main
	clear;
	gcc -g -Wall -Wextra -o main main.c ./libft/libft.a ./libftprintf/libftprintf.a
	clear;
	valgrind --leak-check=full --track-origins=yes ./main
