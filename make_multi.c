/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:36:31 by diavolo           #+#    #+#             */
/*   Updated: 2023/09/21 18:47:10 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_call_bonus(t_cmds *data_exec)
{
	int	i;

	i = -1;
	data_exec->pipe = malloc(sizeof(int *) * data_exec->ncmd);
	if (!data_exec->pipe)
		return (-1);
	while (++i < data_exec->ncmd)
	{
		data_exec->pipe[i] = malloc(sizeof(int) * 2);
		if (!data_exec->pipe[i])
			return (ft_free_int(data_exec, i), -1);
	}
	i = -1;
	while (++i < data_exec->ncmd)
	{
		if (pipe(data_exec->pipe[i]) == -1)
		{
			if (data_exec->here == 1)
				unlink(".tmp_5546412sdfsdg46351g5fs646129");
			return (ft_free_int(data_exec, -1), perror("Error creating pipes"), -1);
		}
	}
	return (ft_make_bonus(data_exec));
}

int	ft_make_bonus(t_cmds *data_exec)
{
	pid_t	pid;
	int		i;
	int		pids[1024];

	i = -1;
	while (++i < data_exec->ncmd)
	{
		pid = fork();
		if (pid == -1)
			return (unlink(".tmp_5546412sdfsdg46351g5fs646129"),
				perror("Error process"), ft_free_int(data_exec, -1), exit(-1), -1);
		if (pid == 0)
			ft_pipe_action(data_exec, i);
		else
			pids[i] = pid;
	}
	ft_close_all(data_exec);
	i = -1;
	while (++i < data_exec->ncmd)
		waitpid(pids[i], NULL, 0);
	if (data_exec->here == 1)
		unlink(".tmp_5546412sdfsdg46351g5fs646129");
	ft_free_int(data_exec, -1);
	return (0);
}

void	ft_pipe_action(t_cmds *data_exec, int i)
{
	if (i == 0)
		ft_first_pipe(data_exec, i);
	else if (i == (data_exec->ncmd - 1))
		ft_last_pipe(data_exec, i);
	else
		ft_inter_pipe(data_exec, i);
}

void	ft_close_all(t_cmds *data_exec)
{
	int	i;

	i = -1;
	while (++i < data_exec->ncmd)
		ft_close_fd(data_exec->pipe[i]);
	if (data_exec->infile != -1)
		close(data_exec->infile);
    close(data_exec->outfile);
}