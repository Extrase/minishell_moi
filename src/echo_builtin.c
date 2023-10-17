/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:29:51 by thenry            #+#    #+#             */
/*   Updated: 2023/10/17 16:23:34 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo_builtin(char *cmds)
{
	int	i;

	i = 0;
	if (ft_strncmp(cmds, "echo -n ", 8) == 0)
	{
		i += 8;
		while (cmds[i])
			printf("%c", cmds[i++]);
	}
	else if (ft_strncmp(cmds, "echo -n", 7) == 0)
	{
		exit_status = 0;
		return (exit_status);
	}
	else if (ft_strncmp(cmds, "echo ", 5) == 0)
	{
		i += 5;
		while (cmds[i])
			printf("%c", cmds[i++]);
		printf("\n");
	}
	else
		printf("\n");
	exit_status = 0;
	return (exit_status);
}
