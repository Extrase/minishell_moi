/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:55:55 by thenry            #+#    #+#             */
/*   Updated: 2023/09/20 16:50:57 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//----------------- TUTO -----------------------//
/*
https://medium.com/@mohammedisam2000/lets-build-a-linux-shell-part-i-954c95911501
https://m4nnb3ll.medium.com/minishell-building-a-mini-bash-a-42-project-b55a10598218
*/
//----------------- GET TYPE ---------------------//

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

//----------- REMOVE BLANK SECOND LIST --------------------//

void	remove_blank(t_second_lst *second_list)
{
	t_second_lst *tmp;

	tmp = second_list;
	while (tmp)
	{
		if (tmp->token_type == BLANK)
		{
			tmp->next = tmp->next->next;
		}
		else
			tmp = tmp->next;
	}
}






//-------------- AFFECT TOKEN TYPE ----------------------//

int	ft_affect_tok_type(char *token)
{
	if (token[0] == '$')
		return (ENVVAR);
	else if (token[0] == '-')
		return (ARG);
	else if (token[0] == '\'' || token[0] == '\"')
		return (WORD);
	return (OTHERR);
}



//------------- SECOND LIST UTILS -----------------------//

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

t_second_lst	*fill_second_list(t_first_lst *first_list)
{
	//int	i;
	char	*tok;
	char	*tmp;
	int	tok_type;
	t_second_lst	*second_list = NULL;
	t_second_lst	*new;

	//i = 0;
	while (first_list)
	{
		tok = first_list->cs;
		// CAS 2 - LES CHAR SONT A L'INTERIEUR DE SQUOTES OU DQUOTES
		if (first_list->type == SQUOTE || first_list->type == DQUOTE)
		{
			while (first_list->next && !(first_list->next->type == '\'' || first_list->next->type == '\"'))
			{
				tmp = ft_strjoin(tok, first_list->next->cs);
				tok = tmp;
				first_list = first_list->next;
			}
		}
		// CAS 3 - VARIABLES D'ENVIRONNEMENT
		if (first_list->type == DOLLAR)
		{
			while (first_list->next && !(first_list->next->type == FTSPACE || first_list->next->type == FTTAB))
			{
				tmp = ft_strjoin(tok, first_list->next->cs);
				tok = tmp;
				first_list = first_list->next;
			}
		}	
		// CAS 4 - COMMAND ARGUMENTS	
		if (first_list->type == DASH)
		{
			while (first_list->next && !(first_list->next->type == FTSPACE || first_list->next->type == FTTAB))
			{
				tmp = ft_strjoin(tok, first_list->next->cs);
				tok = tmp;
				first_list = first_list->next;
			}
		}	

		// CAS 5 - TAB OR SPACE
			while (first_list->next && !(first_list->next->type == FTSPACE || first_list->next->type == FTTAB))
			{
				tmp = ft_strjoin(tok, first_list->next->cs);
				tok = tmp;
				first_list = first_list->next;
			}	
		// CAS 6 - SQUOTES & DQUOTES UNCLOSED

		// CAS 1 - LES CHAR SONT IDENTIQUES
		while (first_list->next && (first_list->type == first_list->next->type))
		{
			tmp = ft_strjoin(tok, first_list->next->cs);
			tok = tmp;
			first_list = first_list->next;
		}
		//------------ AFFECT TOKEN VALUE --------------------//
		
		tok_type = ft_affect_tok_type(tok);
		
		//----------------------------------------//
		
		new = ft_second_lst_new(tok, tok_type);
		ft_second_lst_add_back(&second_list, new);
		first_list = first_list->next;
	}
	return (second_list);
}

void	print_second_lst(t_second_lst *list)
{
	t_second_lst *tmp;

	tmp = list;
	while (tmp)
	{
		printf("token = '%s' & token type = '%d'\n", tmp->token, tmp->token_type);
		tmp = tmp->next;
	}
}

//----------- FILL FIRST LIST UTILS --------------------//

t_first_lst	*ft_lst_last(t_first_lst *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

t_first_lst	*ft_lst_new(char character)
{
	t_first_lst	*new;

	new = malloc(sizeof(t_first_lst));
	if (!new)
		return (NULL);
	new->c = character;
	new->cs[0] = character;
	new->cs[1] = '\0';
	new->type = get_type(character);
	new->next = NULL;
	return (new);
}

void	ft_lst_add_back(t_first_lst **a, t_first_lst *new)
{
	t_first_lst	*tmp;

	if (*a == NULL)
	{
		*a = new;
		return ;
	}
	tmp = ft_lst_last(*a);
	tmp->next = new;
}

t_first_lst	*fill_list_tmp(char *prompt)
{
	int	i;
	t_first_lst	*list = NULL;
	t_first_lst	*new;

	i = 0;
	while (prompt[i])
	{
		new = ft_lst_new(prompt[i]);
		ft_lst_add_back(&list, new);
		i++;
	}
	return (list);
}

void	print_lst(t_first_lst *list)
{
	t_first_lst *tmp;

	tmp = list;
	while (tmp)
	{
		printf("char = '%c' & type = '%d'\n", tmp->c, tmp->type);
		tmp = tmp->next;
	}
}

//------------- MAIN --------------//

int	main(int ac, char **av, char **env)
{
	char		*prompt;
	t_first_lst	*first_list;
	t_second_lst	*second_list;

	(void)ac;
	(void)av;
	(void)env;

	while (1)
	{
		prompt = readline("minishell:~$ ");
		first_list = fill_list_tmp(prompt);
		print_lst(first_list);
		printf("---------------------------\n");
		second_list = fill_second_list(first_list);
		print_second_lst(second_list);	
		printf("---------------------------\n");	
		remove_blank(second_list);
		print_second_lst(second_list);	
		if (ft_strnstr(prompt, "exit", ft_strlen(prompt)))
			break ;
	}
	return (0);
}
