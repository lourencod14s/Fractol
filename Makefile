# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldias-fe <ldias-fe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 03:24:15 by ldias-fe          #+#    #+#              #
#    Updated: 2023/02/01 18:21:12 by ldias-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
MLX_PATH = ../minilibx-linux/
INCLUDES = -I $(MLX_PATH)
PATH_LIBS = -L$(MLX_PATH)
LIBS = -lmlx -lX11 -lXext -lm
FLAGS = -Wall -Wextra -Werror -g3
LB   	= \033[0;36m
B		= \033[0;34m
Y  		= \033[1;33m
G		= \033[7;32m
R 		= \033[1;31m
X		= \033[m

SRCS 	= 	main.c		\
			validation.c\
			mandelbrot.c\
			julia.c 	\
			hooks.c   	\
			utils.c
			

OBJS 		= $(SRCS:.c=.o)

$(NAME): 	$(OBJS)
	@make -C $(MLX_PATH) --no-print-directory
	cc -o $(NAME) $(OBJS) $(LIBS) $(PATH_LIBS) $(INCLUDES)
	@clear
	@echo "$(Y)[#               ] Compiling.  - "
	@sleep 0.2
	@clear
	@echo "$(Y)[##              ] Compiling.  \ "
	@sleep 0.2
	@clear
	@echo "$(Y)[###             ] Compiling.  | "
	@sleep 0.2
	@clear
	@echo "$(Y)[####            ] Compiling.  / "
	@sleep 0.2
	@clear
	@echo "$(Y)[#####           ] Compiling.  - "
	@sleep 0.2
	@clear
	@echo "$(Y)[######          ] Compiling.  \ "
	@sleep 0.2
	@clear
	@echo "$(Y)[#######         ] Compiling.  | "
	@sleep 0.2
	@clear
	@echo "$(Y)[########        ] Compiling.  / "
	@sleep 0.2
	@clear
	@echo "$(Y)[#########       ] Compiling.  - "
	@sleep 0.2
	@clear
	@echo "$(Y)[##########      ] Compiling.  \ "
	@sleep 0.2
	@clear
	@echo "$(Y)[###########     ] Compiling.  | "
	@sleep 0.2
	@clear
	@echo "$(Y)[############    ] Compiling.  / "
	@sleep 0.2
	@clear
	@echo "$(Y)[#############   ] Compiling.  - "
	@sleep 0.2
	@clear
	@echo "$(Y)[##############  ] Compiling.  \ "
	@sleep 0.2
	@clear
	@echo "$(Y)[############### ] Compiling.  | "
	@sleep 0.2
	@clear
	@echo "$(Y)[################] Compiling.  / "
	@sleep 0.2
	@clear
	@echo "$(G) ( ͡° ͜ʖ ͡°) $(NAME) created!!!  (▀̿̿Ĺ̯̿▀̿ ̿) $(X)"
	@sleep 0.2

$(OBJS):	$(SRCS)
		cc $(FLAGS) -I. -c $(SRCS)

all:		$(NAME)

clean:
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME)
		@echo "$(R) ¯\_(ツ)_/¯ objects removed!!!"
		@sleep 1.2
		@clear

re:		fclean all clean

.PHONY: all clean fclean re

