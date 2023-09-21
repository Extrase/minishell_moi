/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by rmechety          #+#    #+#             */
/*   Updated: 2023/05/24 15:49:47 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// typedef struct s_list
// {
// 	int				content;
// 	struct s_list	*next;
// }					t_list;

/* -------------------------------------------------------------------------- */
/*                        FILE = Libft/ft_lstdelone.c                         */
/* -------------------------------------------------------------------------- */
// void				ft_lstdelone(t_list *lst, void (*del)(void *));

/* -------------------------------------------------------------------------- */
/*                          FILE = Libft/ft_memcmp.c                          */
/* -------------------------------------------------------------------------- */
int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			ft_free_list(char **father);
int				ft_strslen(char **str);
/* -------------------------------------------------------------------------- */
/*                       FILE = Libft/ft_lstadd_front.c                       */
/* -------------------------------------------------------------------------- */
// void				ft_lstadd_front(t_list **lst, t_list *new);

/* -------------------------------------------------------------------------- */
/*                          FILE = Libft/ft_memcpy.c                          */
/* -------------------------------------------------------------------------- */
void			*ft_memcpy(void *dest, const void *src, size_t n);

/* -------------------------------------------------------------------------- */
/*                          FILE = Libft/ft_calloc.c                          */
/* -------------------------------------------------------------------------- */
void			*ft_calloc(size_t nmemb, size_t size);

/* -------------------------------------------------------------------------- */
/*                        FILE = Libft/ft_putendl_fd.c                        */
/* -------------------------------------------------------------------------- */
void			ft_putendl_fd(char *s, int fd);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_strnstr.c                          */
/* -------------------------------------------------------------------------- */
char			*ft_strnstr(const char *big, const char *little, size_t len);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_isalpha.c                          */
/* -------------------------------------------------------------------------- */
int				ft_isalpha(int c);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_strtrim.c                          */
/* -------------------------------------------------------------------------- */
char			*ft_strtrim(char const *s1, char const *set);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_lstclear.c                         */
/* -------------------------------------------------------------------------- */
// void				ft_lstclear(t_list *lst);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_memmove.c                          */
/* -------------------------------------------------------------------------- */
void			*ft_memmove(void *dest, const void *src, size_t n);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_isalnum.c                          */
/* -------------------------------------------------------------------------- */
int				ft_isalnum(int c);

/* -------------------------------------------------------------------------- */
/*                       FILE = Libft/ft_lstadd_back.c                        */
/* -------------------------------------------------------------------------- */
// void				ft_lstadd_back(t_list *lst, void *new);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_isdigit.c                          */
/* -------------------------------------------------------------------------- */
int				ft_isdigit(int c);

/* -------------------------------------------------------------------------- */
/*                          FILE = Libft/ft_lstnew.c                          */
/* -------------------------------------------------------------------------- */
// t_list				*ft_lstnew(void *content);
// void				ft_printlist(t_list *list);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_lstsize.c                          */
/* -------------------------------------------------------------------------- */
// int					ft_lstsize(t_list *lst);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_isprint.c                          */
/* -------------------------------------------------------------------------- */
int				ft_isprint(int c);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_tolower.c                          */
/* -------------------------------------------------------------------------- */
int				ft_tolower(int c);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_toupper.c                          */
/* -------------------------------------------------------------------------- */
int				ft_toupper(int c);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_strncmp.c                          */
/* -------------------------------------------------------------------------- */
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/* -------------------------------------------------------------------------- */
/*                          FILE = Libft/ft_strlen.c                          */
/* -------------------------------------------------------------------------- */
size_t			ft_strlene(const char *str);

/* -------------------------------------------------------------------------- */
/*                        FILE = Libft/ft_putstr_fd.c                         */
/* -------------------------------------------------------------------------- */
void			ft_putstr_fd(char *s, int fd);

/* -------------------------------------------------------------------------- */
/*                          FILE = Libft/ft_bzero.c                           */
/* -------------------------------------------------------------------------- */
void			ft_bzero(void *s, size_t n);

/* -------------------------------------------------------------------------- */
/*                          FILE = Libft/ft_memset.c                          */
/* -------------------------------------------------------------------------- */
void			*ft_memset(void *s, int c, size_t n);

/* -------------------------------------------------------------------------- */
/*                          FILE = Libft/ft_substr.c                          */
/* -------------------------------------------------------------------------- */
char			*ft_substr(char const *s, unsigned int start, size_t len);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_strmapi.c                          */
/* -------------------------------------------------------------------------- */
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* -------------------------------------------------------------------------- */
/*                          FILE = Libft/ft_strchr.c                          */
/* -------------------------------------------------------------------------- */
char			*ft_strchr(const char *s, int c);

/* -------------------------------------------------------------------------- */
/*                           FILE = Libft/ft_atoi.c                           */
/* -------------------------------------------------------------------------- */
long long int	ft_atoi(const char *nptr);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_isascii.c                          */
/* -------------------------------------------------------------------------- */
int				ft_isascii(int c);

/* -------------------------------------------------------------------------- */
/*                           FILE = Libft/ft_itoa.c                           */
/* -------------------------------------------------------------------------- */
char			*ft_itoa(int n);

/* -------------------------------------------------------------------------- */
/*                        FILE = Libft/ft_putchar_fd.c                        */
/* -------------------------------------------------------------------------- */
void			ft_putchar_fd(char c, int fd);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_strjoin.c                          */
/* -------------------------------------------------------------------------- */
char			*ft_strjoin(char const *s1, char const *s2);

/* -------------------------------------------------------------------------- */
/*                          FILE = Libft/ft_split.c                           */
/* -------------------------------------------------------------------------- */
char			**ft_split(char *s, char c);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_strlcat.c                          */
/* -------------------------------------------------------------------------- */
size_t			ft_strlcat(char *dst, const char *src, size_t size);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_lstiter.c                          */
/* -------------------------------------------------------------------------- */
// void				ft_lstiter(t_list *lst, void (*f)(void *));

/* -------------------------------------------------------------------------- */
/*                          FILE = Libft/ft_lstmap.c                          */
/* -------------------------------------------------------------------------- */
// t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
// 						void (*del)(void *));

/* -------------------------------------------------------------------------- */
/*                        FILE = Libft/ft_putnbr_fd.c                         */
/* -------------------------------------------------------------------------- */
void			ft_putnbr_fd(int n, int fd);

/* -------------------------------------------------------------------------- */
/*                          FILE = Libft/ft_memchr.c                          */
/* -------------------------------------------------------------------------- */
void			*ft_memchr(const void *s, int c, size_t n);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_strrchr.c                          */
/* -------------------------------------------------------------------------- */
char			*ft_strrchr(const char *s, int c);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_striteri.c                         */
/* -------------------------------------------------------------------------- */
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

/* -------------------------------------------------------------------------- */
/*                          FILE = Libft/ft_strdup.c                          */
/* -------------------------------------------------------------------------- */
char			*ft_strdup(const char *s);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_lstlast.c                          */
/* -------------------------------------------------------------------------- */
// t_list				*ft_lstlast(t_list *lst);

/* -------------------------------------------------------------------------- */
/*                         FILE = Libft/ft_strlcpy.c                          */
/* -------------------------------------------------------------------------- */
size_t			ft_strlcpy(char *dst, const char *src, size_t size);

#endif
