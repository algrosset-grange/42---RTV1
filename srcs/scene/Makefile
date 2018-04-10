# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrosset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/19 19:43:22 by agrosset          #+#    #+#              #
#    Updated: 2017/02/19 19:43:24 by agrosset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	src2.a

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g

SRC_FILES	=	color.c \
				cone.c \
				cylinder.c \
				intersect_info.c \
				light.c \
				material.c \
				plane.c \
				scene.c \
				sphere.c \
				vector_p1.c \
				vector_p2.c \
				vector_p3.c

OBJ			=	$(subst .c,.o,$(SRC_FILES))

H_DIR		=	./../../includes
MLX_PATH	=	./minilibx_macos

GREEN		=	\033[32m
RED			=	\033[31m
DEFAULT		=	\033[37m

.PHONY: clean fclean re all

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib -s $@
	@echo "$(GREEN)$(NAME)$(DEFAULT) created."

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ -I $(H_DIR) $<
	@echo "$(GREEN). \c"

clean:
	@rm -rf $(OBJ)
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)$(NAME)$(DEFAULT) is now deleted for $(NAME)."

re: fclean all
