/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:39:49 by thenry            #+#    #+#             */
/*   Updated: 2023/10/13 17:34:48 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unclosed_singleq(char *token)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (token[i])
	{
		if (token[i] == '\'')
			k++;
		i++;
	}
	if (k % 2 == 0)
	{
		return (0);
	}
	ft_error("Error: unclosed single quotes\n");
	return (1);
}

int	ft_unclosed_doubleq(char *token)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (token[i])
	{
		if (token[i] == '\"')
			k++;
		i++;
	}
	if (k % 2 == 0)
	{
		return (0);
	}
	ft_error("Error: unclosed double quotes\n");
	return (1);
}

char	*ft_no_quotes(char *token, t_mini *mini_env)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (token[i] == '$')
		{
			//printf("token + i = %s\n", token + i);
			token = full_expanded_token(token, mini_env, &i);
			i = -1;
		}
		i++;
	}
	return (token);
}

char	*ft_quotes(char *token, t_mini *mini_env)
{
	int	i;

	if (ft_unclosed_singleq(token))
		return (NULL);
	if (ft_unclosed_doubleq(token))
		return (NULL);
	i = 0;
	if (!ft_strchr(token, '\'') && !ft_strchr(token, '\"'))
	{
		token = ft_no_quotes(token, mini_env);
		return (token);
	}
	while (token[i])
	{
		if (token[i] == '\'')
		{
			i++;
			while (token[i] && token[i] != '\'')
				i++;
		}
		else if (token[i] == '\"')
		{
			i++;
			while (token[i] && token[i] != '\"')
			{
				if (token[i] == '$')
				{
					token = full_expanded_token(token, mini_env, &i);
					i = -1;
					break ;
				}
				i++;
			}
		}
		i++;
	}
	return (token);
}
