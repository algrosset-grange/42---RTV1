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

NAME		=	src1.a

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g

SRC_FILES	=	compute_color.c \
				ft_error.c \
				ft_free_p1.c \
				ft_free_p2.c \
				ft_free_p3.c \
				ft_get_scene_info_p1.c \
				ft_get_scene_info_p2.c \
				ft_get_scene_info_p3.c \
				ft_img_put_pixel.c \
				ft_init.c \
				ft_mlx.c \
				ft_raytracer.c \
				ft_render.c \
				ft_rotate.c \
				ft_rotate_scene_p1.c \
				ft_rotate_scene_p2.c \
				ft_rtvo_move.c \
				ft_vector_normal.c \
				intersect.c \
				main.c \
				re_intersect.c \
				scene_demo_p1.c \
				scene_demo_p2.c

OBJ			= $(subst .c,.o,$(SRC_FILES))

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
	@echo "$(GREEN). $(DEFAULT)\c"

clean:
	@rm -rf $(OBJ)
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)$(NAME)$(DEFAULT) is now deleted for $(NAME)."

re: fclean all
