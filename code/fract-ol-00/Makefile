# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 16:54:23 by yatsu             #+#    #+#              #
#    Updated: 2023/06/06 18:43:26 by yatsu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MAIN =	./main.c

SRC =	${SRC_MAIN}

OBJ =	${SRC:.c=.o}


MINILIBX_LIB =	./minilibx-linux/libmlx.a
MINILIBX_FLAGS = -lX11 -lXext -Lminilibx-linux -lmlx
CC =			cc
CFLAGS =		-g3 -Wall -Wextra -Werror
NAME =			fractol

RM =			rm -rf

MAKE_LIBFT = make -s -C ./libft
LIBFT_A = ./libft/libft.a

all : ${MINILIBX_LIB} ${NAME}

${NAME}: ${OBJ}
	${MAKE_LIBFT}
	${CC} ${OBJ} ${CFLAGS} ${LIBFT_A} -o ${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${MINILIBX_LIB}:
	cd ./minilibx-linux && &{MAKE}

clean :
	${MAKE_LIBFT} fclean
	${RM} ${OBJ}
	${RM} ${OBJ_BONUS}

fclean : clean
	${MAKE_LIBFT} fclean
	${RM} ${NAME}
	${RM} ${NAME_BONUS}

re : fclean all

.PHONY : all clean fclean re
