/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:03:20 by diavolo           #+#    #+#             */
/*   Updated: 2023/10/17 18:08:20 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minishell.h"

char	**make_env(t_mini *mini_env)
{
	char	**env;
	t_mini	*tmp;
	int		i;

	i = 0;
	tmp = mini_env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	env = malloc(sizeof(char *) * i);
	if (!env)
		return (NULL);
	i = 0;
	tmp = mini_env;
	while (tmp)
	{
		env[i] = malloc(sizeof(char) * (ft_strlen(tmp->var) + 1));
		if (!env[i])
			return (ft_free_tabx2(env), NULL);
		i++;
		tmp = tmp->next;
	}
	tmp = mini_env;
	i = 0;
	while (tmp)
	{
		ft_strncpy(env[i], tmp->var, (ft_strlen(tmp->var) + 1));
		i++;
		tmp = tmp->next;
	}
	env[i] = NULL;
	return (env);
}

void	exec(t_cmds **data_exec, t_data *data, t_mini *mini_env)
{
	put_env(data_exec, data, mini_env);
	if (data->ncmd == 1)
	{
		if ((*data_exec)->path)
			exec_builtin(data_exec, mini_env);
		else
			one_pipe(*data_exec);
	}
	else
		Xcution(data_exec, data);
}

void	one_pipe(t_cmds *data_exec)
{
	pid_t	pid;
	int stat;

	stat = 0;
	pid = fork();
	if (pid == 0)
	{
		if ((ft_verif_space(data_exec->cmd) == 1))
			exec_one(data_exec, 0, data_exec->infile, data_exec->outfile);
		else
			exec_two(data_exec, 0, data_exec->infile, data_exec->outfile);
	}
	waitpid(pid, &stat, 0);
	if (WIFEXITED(stat))
		exit_status = WEXITSTATUS(stat);
}
