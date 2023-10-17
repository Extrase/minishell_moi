/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:57:25 by mderkaou          #+#    #+#             */
/*   Updated: 2023/10/13 12:18:59 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minishell.h"

void	read_doc(t_data *data, char *limiter)
{
	char	*line;

	open_read_doc(data);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line)
		{
			if (line && ft_strncmph(line, limiter, ft_strlen(limiter)) == 0)
			{
				free(line);
				get_next_line(-1);
				break ;
			}
			write(data->fd[0], line, ft_strlen(line));
			free(line);
		}
		else
			break ;
	}
	data->fd_tmp = open("tmp_5546412sdfsdg46351g5fs646129", O_RDONLY);
	dup2(data->fd_tmp, data->fd[0]);
	close(data->fd_tmp);
}

void	open_read_doc(t_data *data)
{
	data->fd[0] = open("tmp_5546412sdfsdg46351g5fs646129",
			O_CREAT | O_TRUNC | O_RDWR, 0644);
	data->fd[1] = open(data->av[ft_strslen(data->av)],
			O_CREAT | O_APPEND | O_RDWR, 0644);
	if (data->fd[1] == -1 || data->fd[0] == -1)
		return (ft_close_fd(data->fd), ft_putstr_fd("fd error\n", 2), exit(1));
}

void	here_doc(t_cmds **data_exec, t_data *data)
{

	int i;
	i = -1;
	while (++i < data->ncmd)
	{
		if (data_exec[i]->infile == 2147483647)
		{
			read_doc(&(*data_exec)[i], data_exec[i]->cmd);
		}
	}
}

