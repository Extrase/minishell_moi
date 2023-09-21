/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:31:43 by diavolo           #+#    #+#             */
/*   Updated: 2023/09/21 18:37:43 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	one_pipe(t_cmds *data_exec)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if ((ft_verif_space(data_exec->cmd[0]) == 1))
			ft_make_thing(data_exec, 0, data_exec->infile,
					data_exec->outfile);
		else
			ft_make_thing_two(data_exec, 0, data_exec->infile,
					data_exec->outfile);
	}
    waitpid(pid, NULL, 0);
}