/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_multi2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:39:34 by diavolo           #+#    #+#             */
/*   Updated: 2023/09/21 18:43:23 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_first_pipe(t_cmds *data_exec, int i)
{
	int	j;

	j = 0;
	close(data_exec->outfile);
	close(data_exec->pipe[0][0]);
	while (++j < data_exec->ncmd)
		ft_close_fd(data_exec->pipe[j]);
	if (data_exec->infile == -1)
	{
		close(data_exec->pipe[0][1]);
		ft_free_int(data_exec, -1);
		exit(EXIT_FAILURE);
	}
	if ((ft_verif_space(data_exec->cmd[i]) == 1))
		ft_make_thing(data_exec, i, data_exec->infile, data_exec->pipe[0][1]);
	else
		ft_make_thing_two(data_exec, i, data_exec->infile, data_exec->pipe[0][1]);
}

void	ft_inter_pipe(t_cmds *data_exec, int i)
{
	int	j;

	if (data_exec->infile != -1)
		close(data_exec->infile);
    close(data_exec->outfile);
	close(data_exec->pipe[i][0]);
	close(data_exec->pipe[i - 1][1]);
	j = -1;
	while (++j < data_exec->ncmd)
		if (j != i && j != (i - 1))
			ft_close_fd(data_exec->pipe[j]);
	if ((ft_verif_space(data_exec->cmd[i]) == 1))
		ft_make_thing(data_exec, i, data_exec->pipe[i - 1][0], data_exec->pipe[i][1]);
	else
		ft_make_thing_two(data_exec, i, data_exec->pipe[i - 1][0], data_exec->pipe[i][1]);
}

void	ft_last_pipe(t_cmds *data_exec, int i)
{
	int	j;

	if (data_exec->infile != -1)
		close(data_exec->infile);
	close(data_exec->pipe[i - 1][1]);
	ft_close_fd(data_exec->pipe[i]);
	j = -1;
	while (++j < (i - 1))
		ft_close_fd(data_exec->pipe[j]);
	if ((ft_verif_space(data_exec->cmd[i]) == 1))
		ft_make_thing(data_exec, i, data_exec->pipe[i - 1][0], data_exec->outfile);
	else
		ft_make_thing_two(data_exec, i, data_exec->pipe[i - 1][0], data_exec->outfile);
}

void	ft_make_thing(t_cmds *data_exec, int i, int read_pipe, int write_pipe)
{
	char	**str;
	char	*path;

	str = ft_split(data_exec->cmd[i], ' ');
	path = ft_path_bin(str[0], data_exec->env);
	if (!path || !str)
	{
		if (str)
			ft_free_tabx2(str);
		ft_putstr_fd("minishell: ", 2);
		perror(data_exec->cmd[i]);
		ft_free_int(data_exec, -1);
		exit(EXIT_FAILURE);
	}
	dup2(write_pipe, STDOUT_FILENO);
	dup2(read_pipe, STDIN_FILENO);
	close(read_pipe);
	close(write_pipe);
	execve(path, str, data_exec->env);
	ft_free_int(data_exec, -1);
	exit(-1);
}

void	ft_make_thing_two(t_cmds *data_exec, int i, int read_pipe, int write_pipe)
{
	char	*path;
	char	*arr[2];

	path = ft_path_bin(data_exec->cmd[i], data_exec->env);
	if (!path)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(data_exec->cmd[i]);
		ft_free_int(data_exec, -1);
		exit(EXIT_FAILURE);
	}
	arr[0] = path;
	arr[1] = NULL;
	dup2(write_pipe, STDOUT_FILENO);
	dup2(read_pipe, STDIN_FILENO);
	close(write_pipe);
	close(read_pipe);
	execve(path, arr, data_exec->env);
	ft_free_int(data_exec, -1);
	exit(-1);
}