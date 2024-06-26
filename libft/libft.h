/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:08:23 by kbutor-b          #+#    #+#             */
/*   Updated: 2024/03/11 14:45:58 by kbutor-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct gnl_list
{
	char			*content;
	struct gnl_list	*next;
}	t_gnl;

int			ft_atoi(const char *str);
void		ft_bzero(void *str, size_t n);
void		*ft_calloc(size_t n, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void		*ft_memchr(const void *str, int c, size_t n);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *str, int c, size_t n);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *src);
int			ft_strlcat(char *dest, const char *src, size_t size);
int			ft_strlcpy(char *dest, const char *src, size_t size);
int			ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *str, const char *tofind, size_t n);
char		*ft_strrchr(const char *str, int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int			ft_printf(const char *str, ...);
int			check_str(const char *str, va_list params, int n);
void		print_str(char c, va_list params, int *n);
void		ft_putstr(char *str, int *n);
void		ft_putchar(char c, int *n);
void		ft_putnbr_base(long long int n, char *base, int *nb);
void		ft_putupper_base(long long int n, char *base, int *nb);
void		check_unsigned(unsigned int n, int *nb);
void		print_p(unsigned long int n, int *nb);
char		*get_next_line(int fd);
int			line_len(t_gnl *list);
int			new_line(t_gnl *list);
void		lstclear(t_gnl **list);
void		ft_freesplit(char **array, int i);
int			is_sign(int c);
t_gnl		*lstlast(t_gnl *list);
void		free_int_array(int **array, int n);
long int	ft_atol(const char *str);
void		free_array(char **array);
int			ft_wc(char *str);

#endif