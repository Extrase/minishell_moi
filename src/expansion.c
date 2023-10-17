/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:42:01 by thenry            #+#    #+#             */
/*   Updated: 2023/10/13 17:33:57 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
char	*new_var(char *var)
{
        int     i;
        char    *new;

        new = ft_strdup(var);
        i = 0;
        while (new[i] && new[i + 1])
        {
                new[i] = new[i + 1];
                i++;
        }
        if (new[i])
                new[i++] = '=';
        new[i++] = '\0';
        return (new);
}
*/

char	*shift_var(char *ov)
{
	int	i;

	i = 0;
	while (ov[i] && ov[i + 1])
	{
		ov[i] = ov[i + 1];
		i++;
	}
	ov[i] = '=';
	ov[++i] = '\0';
	return (ov);
}

char	*get_var(char *var, t_mini *mini_env, int *i)
{
	char	*only_var;
	int		j;
	t_mini	*tmp;

	tmp = mini_env;
	if (ft_strncmp(var, "$?", 2) == 0)
	{
		if (ft_strlen(ft_itoa(exit_status)) <= 2)
			(*i) += 2;
		else
			(*i) += ft_strlen(ft_itoa(exit_status));
		return (ft_itoa(exit_status));
	}
	only_var = ft_strdup(var);
	if (!only_var)
		return (NULL);
	j = 1;
	while (var[j] && var[j] != ' ' && var[j] != '\t' && var[j] != '$'
		&& var[j] != '\"' && var[j] != '\'')
	{
		only_var[j] = var[j];
		j++;
	}
	only_var[j] = '\0';
	printf("only var = %s\n", only_var);
	only_var = shift_var(only_var);
	printf("only var = %s\n", only_var);
	while (tmp)
	{
		if (ft_strncmp(only_var, tmp->var, ft_strlen(only_var)) == 0)
		{
			(*i) += j;
			return (tmp->var + ft_strlen(only_var));
		}
		tmp = tmp->next;
	}
	(*i) += j;
	return (ft_strdup(""));
}

char	*full_expanded_token(char *token, t_mini *mini_env, int *i)
{
	int		j;
	char	*cpy;

	j = 0;
	cpy = (char *)malloc(sizeof(char) * (*i) + 1);
	if (!cpy)
		return (NULL);
	while (j < (*i))
	{
		cpy[j] = token[j];
		j++;
	}
	cpy[j] = '\0';
	printf("cpy = %s\n", cpy);
	cpy = ft_strjoin(cpy, get_var(token + (*i), mini_env, &(*i)));
	printf("cpy = %s\n", cpy);
	cpy = ft_strjoin(cpy, token + (*i));
	printf("cpy = %s\n", cpy);
	return (cpy);
}
