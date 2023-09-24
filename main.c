/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:07:57 by diavolo           #+#    #+#             */
/*   Updated: 2023/09/24 15:20:39 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char *av[], char *env[])
{
	t_cmds data_exec;
	if (ac >= 4)
	{
		ft_put_data_exec(&data_exec, av, env);
		if (ac == 4)
			one_pipe(&data_exec);
		else
			ft_call_bonus(&data_exec);
	}
}