/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:37:28 by diavolo           #+#    #+#             */
/*   Updated: 2023/09/21 19:07:11 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_doc(t_cmds *data_exec, char *limiter)
{
	char	*line;

	open_read_doc(data_exec);
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
			write(data_exec->infile, line, ft_strlen(line));
			free(line);
		}
		else
			break ;
	}
	data_exec->fd_tmp = open(".tmp_5546412sdfsdg46351g5fs646129", O_RDONLY);
	dup2(data_exec->fd_tmp, data_exec->infile);
	close(data_exec->fd_tmp);
}

void	open_read_doc(t_cmds *data_exec)
{
	data_exec->infile = open(".tmp_5546412sdfsdg46351g5fs646129",
			O_CREAT | O_TRUNC | O_RDWR, 0644);
	data_exec->outfile = open(data_exec->av[ft_strslen(data_exec->av)],
			O_CREAT | O_APPEND | O_RDWR, 0644);
	if (data_exec->outfile == -1 || data_exec->infile == -1)
	{
		if(data_exec->outfile != -1)
			close(data_exec->outfile);
		if (data_exec->infile != -1)
			close(data_exec->infile);
		return (ft_putstr_fd("fd error\n", 2), exit(1));
	}
}