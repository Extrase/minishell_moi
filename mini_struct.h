/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:35:41 by diavolo           #+#    #+#             */
/*   Updated: 2023/09/21 17:53:18 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifndef MINI_STRUCT_H
# define MINI_STRUCT_H

typedef struct s_cmds
{
	int		ncmd;
	int		**pipe;
	int		infile;
	int		outfile;
	int		index;
	char	**cmd;
	char	**env;
	int		here;
	int		fd_tmp;
	char	**av;
}			t_cmds;

#endif