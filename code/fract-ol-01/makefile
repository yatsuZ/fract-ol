# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 14:12:12 by yatsu             #+#    #+#              #
#    Updated: 2023/09/14 21:13:48 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_EVENT		=	zoom.c			\
					color_change.c	\
					fractal_change.c\
					deplacement.c
FOLDER_EVENT	=	event/
EVENT_PATH		=	${addprefix ${FOLDER_EVENT}, ${SRC_EVENT}}

SRC_FRACTAL		=	mystere.c		\
					mandelbrot.c
FOLDER_FRACTAL	=	fractal/
FRACTAL_PATH	=	${addprefix ${FOLDER_FRACTAL}, ${SRC_FRACTAL}}

SRC_STRUCT		=	init_img.c		\
					init_windows.c	\
					init_plan.c
FOLDER_STRUC	=	init_struct/
STRUCT_PATH		=	${addprefix ${FOLDER_STRUC}, ${SRC_STRUCT}}

SRC_NAME_FILES	=	${EVENT_PATH}	\
					${FRACTAL_PATH}	\
					${STRUCT_PATH}	\
					param_jualia.c	\
					add_event.c		\
					draw.c			\
					main.c			\
					parsing.c		\
					color.c
SRC_PATH		=	./src/
SRC				=	${addprefix ${SRC_PATH}, ${SRC_NAME_FILES}} 

OBJ				=	${SRC:.c=.o}

CC				=	cc
CFLAGS			=	-g3 -Wall -Wextra -Werror

MINILIBX_LIB	=	-I ./library/minilibx-linux -L ./library/minilibx-linux
MINILIBX_FLAGS	=	-lmlx -lXext -lX11 -lm

MAKE_MINILIBX	=	make -s -C ./library/minilibx-linux
MAKE_LIBFT		=	make -s -C ./library/libft
LIBFT_A			=	./library/libft/libft.a

NAME			=	fractol

RM				=	rm -rf

### Commande obligatoire

${NAME}: ${OBJ}
	${MAKE_MINILIBX}
	${MAKE_LIBFT}
	${CC} ${CFLAGS} ${MINILIBX_LIB} ${OBJ} ${MINILIBX_FLAGS} ${LIBFT_A} -o ${NAME}

all : ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

.c.o:
	${CC} ${CFLAGS} ${MINILIBX_LIB} $< ${MINILIBX_FLAGS} -c -o ${<:.c=.o}

clean :
	${MAKE_MINILIBX} clean
	${MAKE_LIBFT} fclean
	${RM} ${OBJ}
	${RM} ${OBJ_BONUS}

fclean : clean
	${MAKE_LIBFT} fclean
	${RM} ${NAME}
	${RM} ${NAME_BONUS}

re : fclean all

################# Commande perso

# Verifie la norminette
norme:
	@ clear
	@ bash ./verif_norminette_fractol.sh

propre:
	@ make all -s
	@ make clean -s

test:
	@ clear
	@ make propre -s
	@ clear
	@ echo "Resultat du programme ${NAME} : "
	@ echo
	@ ./${NAME}

val:
	@ clear
	@ make propre -s
	@ clear
	@ echo "Resultat du programme ${NAME} : "
	@ echo
	valgrind --leak-check=full --show-leak-kinds=all ./${NAME}

#################

.PHONY : all clean fclean re