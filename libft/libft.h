/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:53:13 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/05/25 15:58:59 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <wchar.h>

# define ASCII_OFFSET_NUM 48
# define ASCII_OFFSET_ALPHA 32

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_format
{
	char			flags[9];
	int				width;
	int				precision;
	char			size[9];
	char			type;
}				t_format;

/*
** MEMORY FUNCTIONS
*/
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_calloc(size_t nelem, size_t elsize);
void			ft_swap(int *a, int *b);
char			*ft_free_function(char *function, ...);

/*
** CONVERSION FUNCTIONS
*/
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_itoa_base(unsigned int n, char *base);
char			*ft_llitoa(long long n);
char			*ft_llitoa_base(unsigned long long n, char *base);
char			*ft_ftoa(long double d, int precision);

/*
** PRINTING FUNCTIONS
*/

int				ft_printf(const char *fmt, ...);
void			ft_putnbr(int nb);
int				ft_putstr(char *str);
int				ft_putchar(char c);
void			ft_putchar_fd(char s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_base(unsigned long nbr, char *base, int *bytes);

/*
** STRINGS FUNCTIONS
*/

size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little,
					size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_nstrlen(const char *str, size_t maxlen);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_nstrlen(const char *str, size_t maxlen);
char			*ft_strdup(const char *s1);
char			**ft_split(char const *s, char c);

/*
** CHAR FUNCTIONS
*/

int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

/*
** LINKED LISTS FUNCTIONS
*/

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **list, t_list *new);
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstnew(void *content);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/*
** MATH FUNCTIONS
*/

int				ft_sqrt(int nb);
char			*ft_roundup_number(char *nbr);

#endif
