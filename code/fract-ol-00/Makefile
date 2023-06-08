# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 16:54:23 by yatsu             #+#    #+#              #
#    Updated: 2023/06/08 13:08:10 by yatsu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MAIN =	./src/main.c

DOSSIER_GRAPHIQUE =	./src/Graphique/
FICHIER_GRAPHIQUE =	data_struct.c \
					fenetre_event.c

SRC =	${SRC_MAIN} \
		${addprefix ${DOSSIER_GRAPHIQUE}, ${FICHIER_GRAPHIQUE}}

OBJ =	${SRC:.c=.o}

CC =			cc
CFLAGS =		-g3 -Wall -Wextra -Werror
MINILIBX_LIB =		-I ./minilibx-linux -L ./minilibx-linux
MINILIBX_FLAGS =	-lmlx -lXext -lX11 -lm

MAKE_MINILIBX =	make -s -C ./minilibx-linux
MAKE_LIBFT = make -s -C ./libft
LIBFT_A = ./libft/libft.a

NAME =			fractol

RM =			rm -rf

${NAME}: ${OBJ}
	${MAKE_MINILIBX}
	${MAKE_LIBFT}
	${CC} ${CFLAGS} ${MINILIBX_LIB} ${OBJ} ${MINILIBX_FLAGS} ${LIBFT_A} -o ${NAME}

all : ${NAME}

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
	@ bash ./script_sh/verif_norminette_fractol.sh

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