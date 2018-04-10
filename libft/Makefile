# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrosset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 17:04:19 by agrosset          #+#    #+#              #
#    Updated: 2016/11/26 11:56:31 by agrosset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
HDIR		=	./../includes

SRC_FILES	=	ft_acos_deg.c \
				ft_asin_deg.c \
				ft_atan_deg.c \
				ft_atod.c \
				ft_atoi.c \
				ft_bzero.c \
				ft_clean_tab.c \
				ft_cos_deg.c \
				ft_count_word.c \
				ft_dtoa.c \
				ft_get_next_line.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_islower.c \
				ft_isprint.c \
				ft_isupper.c \
				ft_iswhitespace.c \
				ft_itoa.c \
				ft_lstadd.c \
				ft_lstdel.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_ltoa.c \
				ft_match.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c \
				ft_multi_free.c \
				ft_next_prime_nbr.c \
				ft_nmatch.c \
				ft_putchar.c \
				ft_putchar_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putstr.c \
				ft_putstr_fd.c \
				ft_sin_deg.c \
				ft_sort_wordtab.c \
				ft_str_char_occ_exc_wp.c \
				ft_str_cmp_ext.c \
				ft_str_is_c_after_c_tofind.c \
				ft_str_is_c_before_c_tofind.c \
				ft_str_isalpha.c \
				ft_str_isascii.c \
				ft_str_isdigit.c \
				ft_str_isprint.c \
				ft_str_iswhitespace.c \
				ft_str_occurence.c \
				ft_str_realloc.c \
				ft_str_realloc_cat.c \
				ft_str_repl_occ.c \
				ft_str_str_occurence.c \
				ft_str_tolower.c \
				ft_str_toupper.c \
				ft_strcat.c \
				ft_strccat.c \
				ft_strccpy.c \
				ft_strchr.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_strdup_salloc.c \
				ft_strequ.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strlen_salloc.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strnequ.c \
				ft_strnew.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strsplit.c \
				ft_strstr.c \
				ft_strstr_char_occ.c \
				ft_strsub.c \
				ft_tan_deg.c \
				ft_strtrim.c \
				ft_tolower.c \
				ft_toupper.c

GREEN		=	\033[32m
RED			=	\033[31m
DEFAULT		=	\033[37m

OBJ			=	$(subst .c,.o,$(SRC_FILES))

.PHONY: clean fclean re all

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib -s $@
	@echo "$(GREEN)$(NAME)$(DEFAULT) created."

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ -I $(HDIR) $<
	@echo "$(GREEN). \c"

clean:
	@rm -rf $(OBJ)
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)$(NAME)$(DEFAULT) is now deleted for $(NAME)."

re: fclean all
