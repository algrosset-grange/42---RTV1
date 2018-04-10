# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrosset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/19 19:43:22 by agrosset          #+#    #+#              #
#    Updated: 2017/11/27 19:25:09 by agrosset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	rtv1

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
ACCEL_FLAG	=	-Ofast
FLAGSMLX	=	-lmlx 
FLAGFRAMWO	=	-framework OpenGL -framework AppKit

LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a

OBJ_DIR		=	obj/

LIBMLX_DIR	=	minilibx_macos/
LIBMLX		=	$(LIBMLX_DIR)/libmlx.a

SRC_DIR1	=	srcs/main/
SRC1		=	$(SRC_DIR1)/src1.a

SRC_DIR2	=	srcs/scene/
SRC2		=	$(SRC_DIR2)/src2.a

SRC_DIR3	=	srcs/make_scene/
SRC3		=	$(SRC_DIR3)/src3.a

H_DIR		=	./includes
MLX_PATH	=	./minilibx_macos

INCLUDES 	= libft.h mlx.h rtv1.h key_code.h fct_element.h cla_element.h checkjson.h


#INC			= $(patsubst %, $(H_DIR)/%, $(INCLUDES))

GREEN		=	\033[32m
RED			=	\033[31m
DEFAULT		=	\033[37m

.PHONY: all clean fclean re

$(NAME): $(LIBFT) $(SRC1) $(SRC2) $(SRC3)
	@gcc -o $(NAME) $(FLAGS) $(FLAGFRAMWO) $(LIBFT) $(SRC1) $(SRC2) $(SRC3) $(LIBMLX)
	@echo "$(GREEN)$(NAME)$(DEFAULT) created."

all: $(NAME)

$(LIBMLX):
	@make -C $(LIBMLX_DIR) all

$(LIBFT):
	@make -C $(LIBFT_DIR) all

$(SRC1):
	@make -C $(SRC_DIR1) all

$(SRC2):
	@make -C $(SRC_DIR2) all

$(SRC3):
	@make -C $(SRC_DIR3) all

clean:
	@make -C $(SRC_DIR1) clean
	@make -C $(SRC_DIR2) clean
	@make -C $(SRC_DIR3) clean
	@make -C $(LIBFT_DIR) clean
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."

fclean:
	@rm -rf $(NAME)
	@make -C $(LIBMLX_DIR) clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(SRC_DIR1) fclean
	@make -C $(SRC_DIR2) fclean
	@make -C $(SRC_DIR3) fclean
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."
	@echo "$(RED)$(NAME)$(DEFAULT) deleted."

re: fclean all
