/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Xcution.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:05:08 by mderkaou          #+#    #+#             */
/*   Updated: 2023/10/17 18:10:13 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minishell.h"

void	ft_pipe_action(t_cmds *data_exec, int i, t_data *data)
{
	if (i == 0)
		ft_first_pipe(data_exec, i, data);
	else if (i == (data->ncmd - 1))
		ft_last_pipe(data_exec, i, data);
	else
		ft_inter_pipe(data_exec, i, data);
}

int	make_all_exec(t_cmds **data_exec, t_data *data)
{
	pid_t	pid;
	int		i;
	int		pids[1024];
	int stat;

	i = -1;
	stat = 0;
	while (++i < data->ncmd)
	{
		pid = fork();
		if (pid == -1)
			return (unlink(".tmp_5546412sdfsdg46351g5fs646129"), perror("Error process"),
					ft_free_int(data, data_exec, -1), exit(-1), -1);
		if (pid == 0)
			ft_pipe_action(&(*data_exec)[i], i, data);
		else
			pids[i] = pid;
	}
	ft_close_all(data_exec, data);
	i = -1;
	while (++i < data->ncmd)
		waitpid(pids[i], &stat, 0);
	if (WIFEXITED(stat))
		exit_status = WEXITSTATUS(stat);
	if ((*data_exec)->infile == INT_MAX)
		unlink(".tmp_5546412sdfsdg46351g5fs646129");
	ft_free_int(data, data_exec, -1);
	return (0);
}


void	put_env(t_cmds **data_exec, t_data *data, t_mini *mini_env)
{
	int i;

	i = -1;
	while (++i < data->ncmd)
		(*data_exec)[i].mini_env = mini_env;
}

int	Xcution(t_cmds **data_exec, t_data *data)
{
	int i;

	i = -1;

	data->pipe = malloc(sizeof(int *) * data->ncmd);
	if (!data->pipe)
		return (-1);
	while (++i < data->ncmd)
	{
		data->pipe[i] = malloc(sizeof(int) * 2);
		if (!data->pipe[i])
			return (ft_free_int(data, data_exec, i), -1);
	}
	i = -1;
	while (++i < data->ncmd)
	{
		if (pipe(data->pipe[i]) == -1)
		{
			if ((*data_exec)->infile == INT_MAX)
				unlink(".tmp_5546412sdfsdg46351g5fs646129");
			return (ft_free_int(data, data_exec, -1), perror("Error creating pipes"), -1);
		}
	}
	return (make_all_exec(data_exec, data));
}
