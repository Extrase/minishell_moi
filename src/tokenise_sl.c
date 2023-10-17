/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenise_sl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:23:06 by thenry            #+#    #+#             */
/*   Updated: 2023/10/13 17:36:28 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_second_lst	*ft_second_lst_last(t_second_lst *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

t_second_lst	*ft_second_lst_new(char *tok, int tok_type)
{
	t_second_lst	*new;

	new = malloc(sizeof(t_second_lst));
	if (!new)
		return (NULL);
	new->token = tok;
	new->token_type = tok_type;
	new->next = NULL;
	return (new);
}

void	ft_second_lst_add_back(t_second_lst **a, t_second_lst *new)
{
	t_second_lst	*tmp;

	if (*a == NULL)
	{
		*a = new;
		return ;
	}
	tmp = ft_second_lst_last(*a);
	tmp->next = new;
}

int	ft_is_op(char c)
{
	if (c == '>' || c == '<' || c == '|')
		return (1);
	return (0);
}

t_second_lst	*fill_second_list(t_first_lst *first_list)
{
	char			*tok;
	char			*tmp;
	int				tok_type;
	t_second_lst	*second_list;
	t_second_lst	*new;

	second_list = NULL;
	while (first_list)
	{
		// Remove Blank
		while (ft_space(first_list->c) && first_list->next)
		{
			first_list = first_list->next;
		}
		if (ft_space(first_list->c) && !first_list->next)
			break ;
		tok = first_list->cs;
		tok_type = -42;
		// CAS 1 - LES CHAR SONT A L'INTERIEUR DE SQUOTES
		if (first_list->type == SQUOTE)
		{
			while (first_list->next && !(first_list->next->type == FTSPACE)
				&& !(first_list->next->type == FTSPACE))
			{
				tmp = ft_strjoin(tok, first_list->next->cs);
				tok = tmp;
				first_list = first_list->next;
			}
			/*
                        if (first_list->next && first_list->next->c == '\'')
                        {
                                tmp = ft_strjoin(tok, first_list->next->cs);
                                tok = tmp;
                                first_list = first_list->next;
                        }
			*/
			/*
                        while (first_list->next
		&& !(first_list->next->c == '\''))
                        {
                                tmp = ft_strjoin(tok, first_list->next->cs);
                                tok = tmp;
                                first_list = first_list->next;
                        }
                        if (first_list->next && first_list->next->c == '\'')
                        {
                                tmp = ft_strjoin(tok, first_list->next->cs);
                                tok = tmp;
                                first_list = first_list->next;
                        }
			*/
		}
		// CAS 2 - LES CHAR SONT A L'INTERIEUR DE DQUOTES
		else if (first_list->type == DQUOTE)
		{
			while (first_list->next && !(first_list->next->type == FTSPACE)
				&& !(first_list->next->type == FTSPACE))
			{
				tmp = ft_strjoin(tok, first_list->next->cs);
				tok = tmp;
				first_list = first_list->next;
			}
			/*
                        while (first_list->next
		&& !(first_list->next->c == '\"'))
                        {
                                tmp = ft_strjoin(tok, first_list->next->cs);
                                tok = tmp;
                                first_list = first_list->next;
                        }
                        if (first_list->next && first_list->next->c == '\"')
                        {
                                tmp = ft_strjoin(tok, first_list->next->cs);
                                tok = tmp;
                                first_list = first_list->next;
                        }
			*/
		}
		// CAS 3 - VARIABLES D'ENVIRONNEMENT
		else if (first_list->type == DOLLAR)
		{
			while (first_list->next && !(first_list->next->type == FTSPACE
					|| first_list->next->type == FTTAB))
			{
				tmp = ft_strjoin(tok, first_list->next->cs);
				tok = tmp;
				first_list = first_list->next;
			}
		}
		// CAS 4 - PIPE OR REDIRECTIONS
		else if (first_list->type == PIPE || first_list->type == REDIRIN
				|| first_list->type == REDIROUT)
		{
			while (first_list->next
				&& (first_list->type == first_list->next->type))
			{
				tmp = ft_strjoin(tok, first_list->next->cs);
				tok = tmp;
				first_list = first_list->next;
			}
		}
		// CAS 5 - OTHER CHAR
		else
		{
			while (first_list->next && (first_list->next->type != FTSPACE
					&& first_list->next->type != FTTAB
					&& !ft_is_op(first_list->next->c)))
			{
				tmp = ft_strjoin(tok, first_list->next->cs);
				tok = tmp;
				first_list = first_list->next;
			}
		}
		new = ft_second_lst_new(tok, tok_type);
		ft_second_lst_add_back(&second_list, new);
		first_list = first_list->next;
	}
	return (second_list);
}

void	print_second_lst(t_second_lst *list)
{
	t_second_lst	*tmp;

	tmp = list;
	while (tmp)
	{
		printf("token = %s & token type = %d\n", tmp->token, tmp->token_type);
		tmp = tmp->next;
	}
}
