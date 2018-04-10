/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:13:36 by agrosset          #+#    #+#             */
/*   Updated: 2016/12/08 11:14:39 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdarg.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define BUFF_SIZE 10000000

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_plist
{
	char			*tab;
	int				read;
	int				fd;
	int				a_lu;
	char			*ret_line;
	char			*resid;
	struct s_plist	*next;
	struct s_plist	*befo;
}					t_plist;

double				ft_acos_deg(double x);
double				ft_asin_deg(double x);
double				ft_atan_deg(double x);

double				ft_atod(char *str);
int					ft_atoi(const char *str);

void				*ft_bzero(void *b, size_t len);
void				ft_clean_tab(char **tab, int len);

double				ft_cos_deg(double x);
int					ft_count_word(const char *str, char c);
char				*ft_dtoa(double n);

int					ft_get_next_line(const int fd, char **line);

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
int					ft_iswhitespace(int c);

char				*ft_itoa(int n);

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

char				*ft_ltoa(long n);

int					ft_match(char *s1, char *s2);

void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);

void				*ft_multi_free(int a, ...);

int					ft_next_prime_nbr(int nb);

int					ft_nmatch(char *s1, char *s2);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(const char *s);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int i, int fd);
void				ft_putstr(const char *str);
void				ft_putstr_fd(const char *str, int fd);

double				ft_sin_deg(double x);

void				ft_sort_wordtab(char **tab);

int					ft_str_char_occ_exc_wp(char *str, char c_occ, int occ,
						char to_find);

int					ft_str_cmp_ext(const char *str, const char *extension);
int					ft_str_is_c_after_c_tofind(char *str, char to_find);
int					ft_str_is_c_before_c_tofind(char *str, char to_find);

int					ft_str_isalpha(char *str);
int					ft_str_isascii(char *str);
int					ft_str_isdigit(char *str);
int					ft_str_isprint(char *str);
int					ft_str_iswhitespace(char *str);
int					ft_str_occurence(const char *str, int to_find);

void				ft_str_realloc(char **str, size_t add_size);
void				ft_str_realloc_cat(char **dst, const char *src);
void				ft_str_repl_occ(char **str, char occ, char rep);
int					ft_str_str_occurence(const char *str, char *to_find);

void				ft_str_tolower(char *str);
void				ft_str_toupper(char *str);

char				*ft_strcat(char *s1, const char *s2);
char				*ft_strccat(char *dst, const char *src, int c);
char				*ft_strccpy(char *dst, const char *src, int c);
char				*ft_strchr(const char *str, int to_find);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);

char				*ft_strdup(const char *src);
char				*ft_strdup_salloc(char **src);

int					ft_strequ(char const *s1, char const *s2);

void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(const char *s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
size_t				ft_strlen_salloc(char **str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s, const char *to_f, size_t len);
char				*ft_strrchr(const char *str, int to_find);
char				**ft_strsplit(const char *s, char c);
char				*ft_strstr(const char *str, const char *to_find);

char				*ft_strstr_char_occ(char *str, int c, int occ);

char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strtrim(const char *s);

double				ft_tan_deg(double x);

int					ft_tolower(int c);
int					ft_toupper(int c);

#endif
