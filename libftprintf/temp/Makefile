#compilar com print f
#mandar para arqg
#compilar com ft_printf
#mandar para arqr
#fazer diff

PREFIXE		= ./

LIBPATH		= ../

SRCS		= $(addprefix ${PREFIXE}, main_tester.c)
SRCSg		= $(addprefix ${PREFIXE}, main_testerg.c)

OBJS		= ${SRCS:.c=.o}
OBJSg		= ${SRCSg:.c=.o}

NAME		= tester.out
NAMEg		= testerg.out

CC			= gcc

#CFLAGS		= -w -Wall -Werror -Wextra -D PRINT="ft_printf" -g3 -fsanitize=address
#CFLAGSg		= -w -Wall -Werror -Wextra -D PRINT="printf" -g3 -fsanitize=address
CFLAGS		= -Wall -Wextra -g
CFLAGSg		= -Wall -Wextra -g

RM			= rm -f

AR			= ar rc

LIB			= -L${LIBPATH} -lftprintf

PRINTF_MAKE	= ${MAKE} -C ${LIBPATH}

$(NAME):	${OBJS} printmake
			rm -f arq
			${CC} ${CFLAGS} main_tester.o ${LIB} -o tester.out
			./tester.out >> arq

$(NAMEg):	${OBJSg} printmake
			rm -f arqg
			${CC} ${CFLAGSg} main_testerg.o ${LIB} -o testerg.out
			./testerg.out >> arqg

printmake:	
			${PRINTF_MAKE}

all:		${NAME} ${NAMEg}

clean:
			${RM} ${OBJS}
			${PRINTF_MAKE} clean

fclean:		clean
			${RM} ${NAME}
			${PRINTF_MAKE} fclean

re:			fclean all

.PHONY:		all clean fclean re
