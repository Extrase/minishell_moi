/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:25:22 by mderkaou          #+#    #+#             */
/*   Updated: 2023/10/17 18:00:51 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minishell.h"

void	exec_one(t_cmds *data_exec, int i, int read_pipe, int write_pipe)
{
	char	**str;
	char	*path;
	char	**env;

	(void)i;
	str = ft_split(data_exec->cmd, ' ');
	path = ft_path_bin(str[0], data_exec->mini_env);
	if (!path || !str || read_pipe == -1)
	{
		if (str)
			ft_free_tabx2(str);
		if (path)
			free(path);
		ft_putstr_fd("minishell: ", 2);
		perror(data_exec->cmd);
		ft_free_int(data_exec->data, &data_exec, -1);
		exit(EXIT_FAILURE);
	}
	if (write_pipe != 1 && write_pipe != -1)
		dup2(write_pipe, STDOUT_FILENO);
	if (read_pipe != 0 && read_pipe != -1)
		dup2(read_pipe, STDIN_FILENO);
	if (write_pipe != 1 && write_pipe != -1)
		close(write_pipe);
	if (read_pipe != 0 && read_pipe != -1)
		close(read_pipe);
	env = make_env(data_exec->mini_env);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	execve(path, str, env);
	(ft_free_int(data_exec->data, &data_exec, -1), ft_free_tabx2(env));
	exit(-1);
}

void	exec_two(t_cmds *data_exec, int i, int read_pipe, int write_pipe)
{
	char	*path;
	char	*arr[2];
	char	**env;

	(void)i;
	path = ft_path_bin(data_exec->cmd, data_exec->mini_env);
	if (!path || read_pipe == -1)
	{
		if (path)
			free(path);
		ft_putstr_fd("minishell: ", 2);
		perror(data_exec->cmd);
		ft_free_int(data_exec->data, &data_exec, -1);
		exit(EXIT_FAILURE);
	}
	arr[0] = path;
	arr[1] = NULL;
	if (write_pipe != 1 && write_pipe != -1)
		dup2(write_pipe, STDOUT_FILENO);
	if (read_pipe != 0 && read_pipe != -1)
		dup2(read_pipe, STDIN_FILENO);
	if (write_pipe != 1 && write_pipe != -1)
		close(write_pipe);
	if (read_pipe != 0 && read_pipe != -1)
		close(read_pipe);
	env = make_env(data_exec->mini_env);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	execve(path, arr, env);
	(ft_free_int(data_exec->data, &data_exec, -1), ft_free_tabx2(env));
	exit(-1);
}
