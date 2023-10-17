/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenise_fl_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:11:25 by thenry            #+#    #+#             */
/*   Updated: 2023/10/13 17:36:17 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_type(char c)
{
	if (ft_strchr("abcdefghijklmnopqrstuvwxyz", (int)c))
		return (LALPHA);
	else if (ft_strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ", (int)c))
		return (UALPHA);
	else if (ft_strchr("0123456789", (int)c))
		return (NUM);
	else if (c == ' ')
		return (FTSPACE);
	else if (c == '\t')
		return (FTTAB); // useless
	else if (c == '\n')
		return (FTNEWLINE); // useless
	else if (c == '-')
		return (DASH);
	else if (c == ';')
		return (SEMICOL); // should not be interpreted
	else if (c == '\'')
		return (SQUOTE); // unclosed should not be interpreted
	else if (c == '\"')
		return (DQUOTE); // unclosed should not be interpreted
	else if (c == '(')
		return (OPARENT);
	else if (c == ')')
		return (CPARENT);
	else if (c == '&')
		return (AMPERSAND);
	else if (c == '$')
		return (DOLLAR);
	else if (c == '|')
		return (PIPE);
	else if (c == '<')
		return (REDIRIN);
	else if (c == '>')
		return (REDIROUT);
	else if (c == '\\')
		return (ESCAPE); // should not be interpreted
	else if (c == '\0')
		return (EOL);
	return (OTHER);
}

int	ft_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_is_quotes(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

int	ft_is_sep(char c)
{
	if (c == ' ' || c == '\t' || c == '<' || c == '>' || c == '|' || c == '('
		|| c == ')' || c == '$' || c == '&')
		return (1);
	return (0);
}
