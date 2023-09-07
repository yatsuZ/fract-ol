# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 14:26:23 by yzaoui            #+#    #+#              #
#    Updated: 2023/09/07 16:19:07 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Gestion

TOUT_LES_MAKE_FILES =	./fract-ol-00 \
						./fract-ol-01 \
						./mini_lbx_boucle_exemple \
						./mini_lbx_draw_exemple \
						./mini_lbx_envent_exemple \
						./mini_lbx_geometry

EXEC = make -s -C

${NAME}:
	@for dir in ${TOUT_LES_MAKE_FILES}; do \
		${EXEC} $$dir; \
	done
	echo "Tout les make file on make"

fclean:
	@for dir in ${TOUT_LES_MAKE_FILES}; do \
		${EXEC} $$dir fclean; \
	done
	echo "Tout les make file on make"
