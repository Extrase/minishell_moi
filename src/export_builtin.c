/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:08:06 by thenry            #+#    #+#             */
/*   Updated: 2023/10/17 16:40:54 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	export_builtin(t_mini **mini_env, char *cmds)
{
	int		i;
	int		j;
	int		len;
	char	*var;
	t_mini	*new;
	t_mini	*tmp;

	new = NULL;
	i = 0;
	j = 0;
	len = ft_strlen(cmds);
	tmp = *mini_env;
	if (ft_strncmp(cmds, "export", ft_strlen(cmds)) == 0)
	{
		while (tmp)
		{
			j = 0;
			printf("export ");
			while (tmp->var[j] != '=')
			{
				printf("%c", tmp->var[j]);
				j++;
			}
			printf("=\"");
			j++;
			while (tmp->var[j])
			{
				printf("%c", tmp->var[j]);
				j++;
			}
			printf("\"\n");
			tmp = tmp->next;
		}
		exit_status = 0;
	}
	else if (ft_strncmp(cmds, "export =", 8) == 0)
		exit_status = 0;
	else if (ft_strncmp(cmds, "export ", 7) == 0)
	{
		i += 7;
		len = len - i;
		var = (char *)malloc(sizeof(char) * len + 1);
		while (cmds[i])
		{
			var[j] = cmds[i];
			i++;
			j++;
		}
		var[j] = '\0';
		new = ft_mini_new(var);
		ft_mini_add_back(mini_env, new);
		exit_status = 0;
	}
	return (exit_status);
}
