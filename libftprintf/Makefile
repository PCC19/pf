NAME=libftprintf.a

FLAGS=-Wall -Wextra -Werror -g -c

HEADER=ft_printf.h

SRCS= ft_printf.c init_fs.c parse_flags.c parse_fs.c trata_c.c\
		trata_d.c trata_n.c trata_p.c trata_s.c trata_u.c trata_x.c utils1.c\
		utils2.c ftoa_int.c ftoa_frac.c ftoa.c trata_f.c trata_e.c ft_round.c\
		funcoes_debug.c

OBJ= ft_printf.o init_fs.o parse_flags.o parse_fs.o trata_c.o\
		trata_d.o trata_n.o trata_p.o trata_s.o trata_u.o trata_x.o utils1.o\
		utils2.o ftoa_int.o ftoa_frac.o ftoa.o trata_f.o trata_e.o ft_round.o\
		funcoes_debug.o

LIBS= ../libft/libft.a

$(NAME):	$(HEADER)	$(SRCS)
	echo FTPRINTF
	make -C ../libft
	cp $(LIBS) $(NAME)
	gcc $(FLAGS) $(SRCS) $(HEADER) 
	ar rc libftprintf.a $(OBJ)
	ranlib libftprintf.a

all: $(NAME)

clean:
		make -C ../libft clean
		rm -rf $(OBJ)

fclean: clean
		make -C ../libft fclean
		rm -rf $(NAME)

re: fclean all
