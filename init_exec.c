/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:34:53 by diavolo           #+#    #+#             */
/*   Updated: 2023/09/24 15:20:32 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_put_data_exec(t_cmds *data_exec, char **av, char **env)
{
	data_exec->cmd = av;
	data_exec->av = av;
	data_exec->cmd++;
	data_exec->cmd++;
	data_exec->ncmd = (ft_strslen(data_exec->cmd));
	data_exec->env = env;
	if (ft_strncmp(data_exec->av[1], "here_doc", 8) == 0)
	{
		data_exec->here = 1;
		read_doc(data_exec, av[2]);
		data_exec->cmd++;
		data_exec->ncmd = (ft_strslen(data_exec->cmd));
		return ;
	}
	else
	{
		data_exec->here = 0;
		data_exec->infile = open(data_exec->av[1], O_RDONLY);
		data_exec->outfile = open(data_exec->av[ft_strslen(data_exec->av)],
				O_CREAT | O_TRUNC | O_RDWR, 0644);
		if (data_exec->outfile == -1)
			return (close(data_exec->infile), close(data_exec->outfile),
				ft_putstr_fd("fd error\n", 2), exit(1));
	}
}