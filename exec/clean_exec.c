/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:29:36 by diavolo           #+#    #+#             */
/*   Updated: 2023/10/05 16:26:35 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minishell.h"

void	ft_free_tabx2(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		if (str[i])
		{
			while (str[i])
			{
				free(str[i]);
				i++;
			}
		}
		free(str);
	}
	return ;
}

void	ft_free_int(t_data *data, t_cmds **data_exec, int o)
{
	int	i;

	(void)data_exec;
	i = -1;
	if (o != -1)
	{
		while (++i < data->ncmd)
			free(data->pipe[i]);
	}
	// free(data->pipe);
    // free(data_exec);
}

void	ft_close_all(t_cmds **data_exec, t_data *data)
{
	int		i;

	(void)data_exec;
	i = -1;
	while (++i < data->ncmd)
		ft_close_fd(data->pipe[i]);
}

void	ft_close_fd(int *fd)
{
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
}

int	ft_verif_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
