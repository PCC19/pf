# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 13:38:41 by pcunha            #+#    #+#              #
#    Updated: 2020/09/28 13:41:31 by pcunha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

LIBS= ./libft/libft.a

FLAGS=-Wall -Wextra -Werror  -c

HEADER=ft_printf.h

SRCS= ft_printf.c ft_choose_conv.c ft_init_fs.c ft_parse_flags.c ft_parse_fs.c\
		ft_conv_c.c ft_conv_d.c ft_conv_n.c ft_conv_p.c ft_conv_s.c ft_conv_u.c\
		ft_conv_x.c ft_utils1.c ft_utils2.c ft_ftoa_int.c ft_ftoa_frac.c\
		ft_ftoa.c ft_conv_f.c ft_conv_e.c ft_round.c

OBJ= ft_printf.o ft_choose_conv.o ft_init_fs.o ft_parse_flags.o ft_parse_fs.o\
		ft_conv_c.o ft_conv_d.o ft_conv_n.o ft_conv_p.o ft_conv_s.o ft_conv_u.o\
		ft_conv_x.o ft_utils1.o ft_utils2.o ft_ftoa_int.o ft_ftoa_frac.o\
		ft_ftoa.o ft_conv_f.o ft_conv_e.o ft_round.o

HEADER_BONUS=ft_printf_bonus.h

SRCS_BONUS= ft_printf_bonus.c ft_choose_conv_bonus.c ft_init_fs_bonus.c\
			ft_parse_flags_bonus.c ft_parse_fs_bonus.c ft_conv_c_bonus.c\
			ft_conv_d_bonus.c ft_conv_n_bonus.c ft_conv_p_bonus.c\
			ft_conv_s_bonus.c ft_conv_u_bonus.c ft_conv_x_bonus.c\
			ft_utils1_bonus.c ft_utils2_bonus.c ft_ftoa_int_bonus.c\
			ft_ftoa_frac_bonus.c ft_ftoa_bonus.c ft_conv_f_bonus.c\
			ft_conv_e_bonus.c ft_round_bonus.c

OBJ_BONUS= ft_printf_bonus.o ft_choose_conv_bonus.o ft_init_fs_bonus.o\
			ft_parse_flags_bonus.o ft_parse_fs_bonus.o ft_conv_c_bonus.o\
			ft_conv_d_bonus.o ft_conv_n_bonus.o ft_conv_p_bonus.o\
			ft_conv_s_bonus.o ft_conv_u_bonus.o ft_conv_x_bonus.o\
			ft_utils1_bonus.o ft_utils2_bonus.o ft_ftoa_int_bonus.o\
			ft_ftoa_frac_bonus.o ft_ftoa_bonus.o ft_conv_f_bonus.o\
			ft_conv_e_bonus.o ft_round_bonus.o

.PHONY: bonus clean fclean

$(NAME):	$(HEADER)	$(SRCS)
	make -C ./libft
	cp $(LIBS) $(NAME)
	gcc $(FLAGS) $(SRCS) $(HEADER) 
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
		make -C ./libft clean
		rm -rf $(OBJ) $(OBJ_BONUS)
		rm -f $(HEADER).gch $(HEADER_BONUS).gch

fclean: clean
		make -C ./libft fclean
		rm -rf $(NAME)

re: fclean all


bonus:	$(HEADER_BONUS)	$(SRCS_BONUS)
	make -C ./libft
	cp $(LIBS) $(NAME)
	gcc $(FLAGS) $(SRCS_BONUS) $(HEADER_BONUS) 
	ar rc $(NAME) $(OBJ_BONUS)
	ranlib $(NAME)
