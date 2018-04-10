#
#

NAME=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1= $(SRC:.c=.o)
OBJ= $(OBJ1:.m=.o)
CFLAGS+=-O2

GREEN		=	\033[32m
RED			=	\033[31m
DEFAULT		=	\033[37m

all: $(NAME)

$(NAME):	$(OBJ)
	@ar -r $(NAME) $(OBJ)
	@ranlib $(NOM)

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

fclean:
	@rm -rf $(NAME)
	@rm -f $(NAME) $(OBJ) *~
	@rm -f mlx_app
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."
	@echo "$(RED)$(NAME)$(DEFAULT) deleted."

re: clean all
