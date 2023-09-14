# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 14:26:23 by yzaoui            #+#    #+#              #
#    Updated: 2023/09/11 00:17:30 by yatsu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Gestion

TOUT_LES_MAKE_FILES =	./fract-ol-00 \
						./fract-ol-01 \
						./mini_lbx_boucle_exemple \
						./mini_lbx_draw_exemple \
						./mini_lbx_envent_exemple \
						./mini_lbx_geometry \
						./mini_lbx-00 \
						./zoom \

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
