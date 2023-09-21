# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 02:47:34 by diavolo           #+#    #+#              #
#    Updated: 2023/09/21 18:32:05 by diavolo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = minishell
CC         = cc
CFLAGS     = -Wall -Wextra -Werror -g3
SRCS     =   main.c make_multi.c make_multi2.c init_exec.c utils.c path_bin.c  \
			doc.c ft_split_2.c ./libft/ft_strlen.c ./libft/ft_strjoin.c \
			./libft/ft_split.c ./libft/ft_strdup.c ./libft/ft_strncmp.c shame.c\
			./libft/ft_strjoin.c ./libft/ft_atoi.c one_pipe.c\
			./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
			./libft/ft_strlcpy.c ./libft/ft_putstr_fd.c \


OBJS    = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:			all clean fclean re
