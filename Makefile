# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 16:09:12 by thenry            #+#    #+#              #
#    Updated: 2023/10/17 15:57:38 by mderkaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	src/main.c src/error.c src/tokenise_fl.c src/tokenise_fl_utils.c src/history.c src/signal.c src/create_cmds.c src/tokenise_sl.c src/utils.c src/clean_sl.c src/expansion.c src/handle_quotes.c src/free.c src/exit_builtin.c src/echo_builtin.c src/get_env.c src/env_builtin.c src/export_builtin.c src/pwd_builtin.c src/unset_builtin.c src/cd_builtin.c \
			exec/Xcution.c exec/utils_exc.c exec/clean_exec.c exec/exec.c exec/exec_builtin.c\
			exec/exec_tools.c exec/ft_split_spec.c exec/clean_exec2.c exec/one_exec.c\

NAME	= 	minishell

OBJS	= 	${SRCS:.c=.o}

CFLAGS	= 	-Wall -Wextra -Werror -g

CC	= 	cc

LIBR	=	libft/libft.a

all:		${NAME}

.c.o:
		${CC} ${CFLAGS} -MMD -MP -c $< -o ${<:.c=.o}

-include ${SRCS:.c=.d}

${NAME}:	${OBJS}
		make -C libft
		${CC} ${CFLAGS} ${OBJS} ${LIBR} -lreadline -o ${NAME}

clean:
		rm -rf ${OBJS}
		#rm -f draft/main.d
		rm -rf src/*.d
		rm -rf exec/*.d
		make -C libft clean

fclean:		clean
		rm -rf ${NAME}
		make -C libft fclean

re:		fclean all

.PHONY:		all re clean fclean
