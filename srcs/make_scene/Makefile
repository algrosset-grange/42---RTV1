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

NAME		=	src3.a

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g

SRC_FILES	=	check_double_p1.c \
				check_double_p2.c \
				check_int.c \
				check_re_init_p1.c \
				check_re_init_p2.c \
				ft_check.c \
				ft_check_annonce_p1.c \
				ft_check_annonce_p2.c \
				ft_check_init.c \
				ft_check_interlude.c \
				ft_check_part_cone_p1.c \
				ft_check_part_cone_p2.c \
				ft_check_part_cone_p3.c \
				ft_check_part_cone_p4.c \
				ft_check_part_cylinder_p1.c \
				ft_check_part_cylinder_p2.c \
				ft_check_part_cylinder_p3.c \
				ft_check_part_cylinder_p4.c \
				ft_check_part_light_p1.c \
				ft_check_part_light_p2.c \
				ft_check_part_light_p3.c \
				ft_check_part_material_p1.c \
				ft_check_part_material_p2.c \
				ft_check_part_p1.c \
				ft_check_part_plane_p1.c \
				ft_check_part_plane_p2.c \
				ft_check_part_plane_p3.c \
				ft_check_part_plane_p4.c \
				ft_check_part_scene_p1.c \
				ft_check_part_scene_p2.c \
				ft_check_part_scene_p3.c \
				ft_check_part_sphere_p1.c \
				ft_check_part_sphere_p2.c \
				ft_check_part_sphere_p3.c \
				ft_check_utile.c \
				ft_make_scene.c

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
	@echo "$(GREEN). \c"

clean:
	@rm -rf $(OBJ)
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)$(NAME)$(DEFAULT) is now deleted for $(NAME)."

re: fclean all