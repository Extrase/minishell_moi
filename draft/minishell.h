/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:28:03 by thenry            #+#    #+#             */
/*   Updated: 2023/09/05 13:30:36 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

#include <readline/readline.h>
#include <readline/history.h>

enum char_type
{
	LALPHA,		// lower case letter
	UALPHA,		// UPPER CASE LETTER
	NUM,		// numeric
	FTSPACE,	// space character ' '
	FTTAB,		// tab character "	" (\t)
	FTNEWLINE,	// '\n'
	DASH,		// -
	SEMICOL,	// ;
	SQUOTE,		// ''
	DQUOTE,		// ""
	OPARENT,	// (
	CPARENT,	// )
	AMPERSAND,	// &
	DOLLAR,		// $
	PIPE,		// |
	REDIRIN,	// < (redirect the input)
	REDIROUT,	// > (it does redirect the output)
	ESCAPE,		// escape character '\'
	EOL,		// '\0'
	OTHER		// other char / wrong char
};

enum token_type
{
	WORD,
	OPERATOR,
	ARG,
	ENVVAR,
	BLANK,
	OTHERR
};

typedef struct s_first_lst
{
	char			c;
	char			cs[2];
	int			type;
	struct	s_first_lst	*next;
}			t_first_lst;

typedef	struct	s_second_lst
{
	char	*token;
	int	token_type;
	struct	s_second_lst	*next;
}			t_second_lst;

#endif
