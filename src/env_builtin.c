/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:56:50 by thenry            #+#    #+#             */
/*   Updated: 2023/10/13 17:33:03 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_builtin(t_mini **mini, char *cmds)
{
	t_mini	*tmp;

	tmp = *mini;
	if (!tmp)
	{
		printf("\n");
		exit_status = 0;
		return (exit_status);
	}
	else if (ft_strcmp(cmds, "env"))
	{
		ft_putstr_fd("env: '", 2);
		ft_putstr_fd(cmds + 4, 2);
		ft_putstr_fd("': No such file or directory\n", 2);
		exit_status = 127;
		return (exit_status);
	}
	else
	{
		while (tmp)
		{
			printf("%s\n", tmp->var);
			tmp = tmp->next;
		}
		exit_status = 0;
	}
	return (exit_status);
}
