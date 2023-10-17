/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:49:37 by thenry            #+#    #+#             */
/*   Updated: 2023/10/13 17:34:22 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lst_clear_fl(t_first_lst **list)
{
	t_first_lst	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		(*list) = tmp;
	}
}

void	ft_lst_clear_sl(t_second_lst **list)
{
	t_second_lst	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		(*list) = tmp;
	}
}
