/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:57:38 by thenry            #+#    #+#             */
/*   Updated: 2023/10/13 17:33:41 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_numeric(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) || *str != '-')
			return (1);
		str++;
	}
	return (1);
}

int	exit_builtin(char **cmds)
{
	if (ft_strcmp(cmds[0], "exit") == 0)
	{
		if (!cmds[1])
		{
			ft_putstr_fd("exit\n", 1);
			exit_status = 0;
			exit(exit_status);
		}
		else if (cmds[1] && is_numeric(cmds[1]))
		{
			if (!cmds[2])
			{
				ft_putstr_fd("exit\n", 1);
				exit_status = ft_atoi(cmds[1]);
				exit(exit_status);
			}
			else
			{
				ft_putstr_fd("minishell: exit: too many arguments\n", 2);
				exit_status = 1;
				return (exit_status);
			}
		}
		else
		{
			ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
			exit_status = 2;
			exit(exit_status);
		}
	}
	return (exit_status);
}
