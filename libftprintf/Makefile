NAME=libftprintf.a

FLAGS=-Wall -Wextra -Werror -g -c

HEADER=ft_printf.h

SRCS= ft_printf.c ft_choose_conv.c ft_init_fs.c ft_parse_flags.c ft_parse_fs.c ft_conv_c.c\
		ft_conv_d.c ft_conv_n.c ft_conv_p.c ft_conv_s.c ft_conv_u.c ft_conv_x.c ft_utils1.c\
		ft_utils2.c ft_ftoa_int.c ft_ftoa_frac.c ft_ftoa.c ft_conv_f.c ft_conv_e.c ft_round.c

OBJ= ft_printf.o ft_choose_conv.o ft_init_fs.o ft_parse_flags.o ft_parse_fs.o ft_conv_c.o\
		ft_conv_d.o ft_conv_n.o ft_conv_p.o ft_conv_s.o ft_conv_u.o ft_conv_x.o ft_utils1.o\
		ft_utils2.o ft_ftoa_int.o ft_ftoa_frac.o ft_ftoa.o ft_conv_f.o ft_conv_e.o ft_round.o

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
