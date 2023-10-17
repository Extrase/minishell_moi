/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_sl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:37:36 by thenry            #+#    #+#             */
/*   Updated: 2023/10/13 17:31:17 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_remove_quotes(char *token)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	cpy = (char *)malloc(sizeof(char) * ft_strlen(token) + 1);
	if (!cpy)
		return (NULL);
	while (token[i])
	{
		if (token[i] == '\'')
		{
			i++;
			while (token[i] && token[i] != '\'')
			{
				cpy[j] = token[i];
				i++;
				j++;
			}
			i++;
			continue ;
		}
		else if (token[i] == '\"')
		{
			i++;
			while (token[i] && token[i] != '\"')
			{
				cpy[j] = token[i];
				i++;
				j++;
			}
			i++;
			continue ;
		}
		cpy[j] = token[i];
		if (token[i])
			i++;
		j++;
		//printf("cpy iteration = %s\n", cpy);
	}
	cpy[j] = '\0';
	//printf("str = %s\n", cpy);
	return (cpy);
}

int	ft_in_quotes(char *token)
{
	int	i;

	i = 0;
	if (!token)
		return (0);
	while (token[i] && (token[i] != '\'' || token[i] != '\"'))
		i++;
	if (token[i] == '\0')
		return (0);
	i++;
	while (token[i])
		i++;
	i--;
	if (token[i] == '\'' || token[i] == '\"')
		return (1);
	return (0);
}

t_second_lst	*clean_second_list(t_second_lst *second_list, t_mini *mini_env)
{
	t_second_lst	*tmp;

	tmp = second_list;
	while (tmp)
	{
		// find unclosed single quotes and double quotes and do expand
		tmp->token = ft_quotes(tmp->token, mini_env);
		tmp = tmp->next;
	}
	tmp = second_list;
	while (tmp)
	{
		// Determine Token Type
		if (!ft_strcmp((tmp->token), ">>"))
			tmp->token_type = DGREAT;
		else if (!ft_strcmp((tmp->token), "<<"))
			tmp->token_type = DLESS;
		else if (!ft_strcmp((tmp->token), ">"))
			tmp->token_type = GREAT;
		else if (!ft_strcmp((tmp->token), "<"))
			tmp->token_type = LESS;
		else if (!ft_strcmp((tmp->token), "|"))
			tmp->token_type = SPIPE;
		else if (ft_in_quotes(tmp->token) == 0)
			tmp->token_type = WORD;
		else if (ft_crap_operator(tmp->token))
		{
			ft_error("Error: parsing error\n");
			return (NULL);
		}
		else
			tmp->token_type = WORD;
		tmp = tmp->next;
	}
	// Remove outer quotes
	tmp = second_list;
	while (tmp)
	{
		if (tmp->token_type == WORD)
		{
			tmp->token = ft_remove_quotes(tmp->token);
		}
		tmp = tmp->next;
	}
	// check PIPE a the beginning or the end
	tmp = second_list;
	if (tmp->token_type == SPIPE)
	{
		ft_error("Error: Pipe at the beginning\n");
		return (NULL);
	}
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->token_type == SPIPE)
	{
		ft_error("Error: Pipe at the end\n");
		return (NULL);
	}
	return (second_list);
}

int	ft_crap_operator(char *token)
{
	if (ft_strchr(token, '>') && (ft_strcmp(token, ">") || ft_strcmp(token,
				">>")))
		return (1);
	else if (ft_strchr(token, '<') && (ft_strcmp(token, "<") || ft_strcmp(token,
					"<<")))
		return (1);
	else if (ft_strchr(token, '|') && ft_strcmp(token, "|"))
		return (1);
	return (0);
}
