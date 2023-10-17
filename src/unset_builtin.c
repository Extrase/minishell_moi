/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:53:02 by thenry            #+#    #+#             */
/*   Updated: 2023/10/12 22:50:03 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_var(t_mini *mini_env, char *var)
{
	t_mini *tmp;
	t_mini *current;

	current = mini_env;
	if (ft_strcmp(current->var, var) == 0)
	{
		tmp = current->next;
		free(current);
		return ;
	}
	while (current->next != NULL)
	{
		if (ft_strncmp(current->next->var, var, ft_strlen(var)) == 0)
		{
			tmp = current->next;
			current->next = current->next->next;
			free(tmp);
			return ;
		}
		current = current->next;
	}
	return ;
}

int	unset_builtin(t_mini **mini_env, char *cmds)
{
	char	*var;
	int	len;
	int	i;
	int	j;
	t_mini	*tmp;

	tmp = *mini_env;
	i = 0;
	j = 0;
	len = ft_strlen(cmds);
	if (ft_strncmp(cmds, "unset ", 6) == 0)
	{
		i += 6;
		len = len - i;
		var = (char *)malloc(sizeof(char) * len + 1);
		if (!var)
			return (-1);
		while (cmds[i] && cmds[i] != '=')
		{
			var[j] = cmds[i];
			i++;
			j++;
		}
		var[j] = '\0';
		delete_var(tmp, var);
	}
	exit_status = 0;
	return (exit_status);
}
