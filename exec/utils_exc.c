/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:16:30 by diavolo           #+#    #+#             */
/*   Updated: 2023/10/17 18:01:06 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minishell.h"

void	ft_make_thing(t_cmds *data_exec, int i, int read_pipe, int write_pipe)
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
	{
		dup2(write_pipe, STDOUT_FILENO);
		close(write_pipe);
	}
	if (read_pipe != 0 && read_pipe != -1)
	{
		dup2(read_pipe, STDIN_FILENO);
		close(read_pipe);
	}
	env = make_env(data_exec->mini_env);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	execve(path, str, env);
	(ft_free_int(data_exec->data, &data_exec, -1), ft_free_tabx2(env));
	exit(-1);
}

void	ft_make_thing_two(t_cmds *data_exec, int i, int read_pipe, int write_pipe)
{
	char	*path;
	char	*arr[2];
	char	**env;

	(void)i;
	i = 0;
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
	{
		dup2(write_pipe, STDOUT_FILENO);
		close(write_pipe);
	}
	if (read_pipe != 0 && read_pipe != -1)
	{
		dup2(read_pipe, STDIN_FILENO);
		close(read_pipe);
	}
	env = make_env(data_exec->mini_env);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	execve(path, arr, env);
	(ft_free_int(data_exec->data, &data_exec, -1), ft_free_tabx2(env));
	exit(-1);
}

void	ft_first_pipe(t_cmds *data_exec, int i, t_data *data)
{
	int	j;

	j = 0;
	if (data_exec->outfile != -1 && data_exec->outfile != 0)
		close(data_exec->outfile);
	close(data->pipe[0][0]);
	while (++j < data->ncmd)
		ft_close_fd(data->pipe[j]);
	if (data_exec->infile == -1)
	{
		close(data->pipe[0][1]);
		ft_free_int(data, &data_exec, -1);
		exit(EXIT_FAILURE);
	}
	if ((ft_verif_space(data_exec->cmd) == 1))
		ft_make_thing(data_exec, i, data_exec->infile, data->pipe[0][1]);
	else
		ft_make_thing_two(data_exec, i, data_exec->infile, data->pipe[0][1]);
}

void	ft_inter_pipe(t_cmds *data_exec, int i, t_data *data)
{
	int	j;

	if (data_exec->infile != -1 && data_exec->infile != 1)
		close(data_exec->infile);
	if (data_exec->outfile != -1 && data_exec->outfile != 0)
    	close(data_exec->outfile);
	close(data->pipe[i][0]);
	close(data->pipe[i - 1][1]);
	j = -1;
	while (++j < data->ncmd)
		if (j != i && j != (i - 1))
			ft_close_fd(data->pipe[j]);
	if ((ft_verif_space(data_exec->cmd) == 1))
		ft_make_thing(data_exec, i, data->pipe[i - 1][0], data->pipe[i][1]);
	else
		ft_make_thing_two(data_exec, i, data->pipe[i - 1][0], data->pipe[i][1]);
}

void	ft_last_pipe(t_cmds *data_exec, int i, t_data *data)
{
	int	j;

	close(data->pipe[i - 1][1]);
	ft_close_fd(data->pipe[i]);
	j = -1;
	while (++j < (i - 1))
		ft_close_fd(data->pipe[j]);
	if (data_exec->infile != 0)
	{
		close(data->pipe[i - 1][0]);
		if ((ft_verif_space(data_exec->cmd) == 1))
			ft_make_thing(data_exec, i, data_exec->infile, data_exec->outfile);
		else
			ft_make_thing_two(data_exec, i, data_exec->infile, data_exec->outfile);
	}
	else
		close(data_exec->infile);
	if ((ft_verif_space(data_exec->cmd) == 1))
		ft_make_thing(data_exec, i, data->pipe[i - 1][0], data_exec->outfile);
	else
		ft_make_thing_two(data_exec, i, data->pipe[i - 1][0], data_exec->outfile);
}
