/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:21:43 by diavolo           #+#    #+#             */
/*   Updated: 2023/09/21 16:58:58 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close_fd(int *fd)
{
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
}

void	ft_free_int(t_cmds *data_exec, int o)
{
	int	i;

	i = 0;
	if (o != -1)
	{
		while (i < data_exec->ncmd)
		{
			free(data_exec->pipe[i]);
			i++;
		}
	}
	else
	{
		while (i < data_exec->ncmd)
		{
			free(data_exec->pipe[i]);
			i++;
		}
	}
	free(data_exec->pipe);
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
