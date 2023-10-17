/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:57:01 by thenry            #+#    #+#             */
/*   Updated: 2023/10/17 15:42:39 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TO DO
// 1. do CD builtin PROPREMENT
// 2. handle heredoc
// 3. free all that shit
// 4. mettre les exit_status partout

int	exit_status;

int	main(int ac, char **av, char **env)
{
	char			*prompt;
	t_first_lst		*first_list;
	t_second_lst	*second_list;
	t_cmds			*cmd_list;
	t_mini			*mini_env;
	t_data			data;

	mini_env = NULL;
	exit_status = 0;
	(void)av;
	if (ac > 1)
	{
		ft_putstr_fd("Error: too many args\n", 2);
		return (1);
	}
	// Init mini_env
	mini_env = get_mini_env(env);
	// Shell Infinite Loop
	while (1)
	{
		// Init Signals
		init_signals();
		// Readline
		prompt = readline("minishell:~$ ");
		// Add Line to History
		if (prompt)
		{
			if (bool_history(prompt) == 1)
				add_history(prompt);
			else
			{
				free(prompt);
				continue ;
			}
			// Tokenise char by char
			first_list = fill_list_tmp(prompt);
			print_lst(first_list);
			// ft_lst_clear_fl(&first_list);


			// Tokenise token by token
			second_list = fill_second_list(first_list);
			print_second_lst(second_list);
			//ft_lst_clear_fl(&first_list);
			//first_list = NULL;

			// Clean Token and affect token type
			second_list = clean_second_list(second_list, mini_env);
			print_second_lst(second_list);

			// Create Structures for MEHDI
			cmd_list = create_cmds(second_list);
			print_cmd_list(cmd_list, second_list);
			//ft_lst_clear_sl(&second_list);
			//second_list = NULL;

			// Exec

			data.ncmd = count_cmd(second_list);
			exec(&cmd_list, &data, mini_env);
			// FREE Prompt
			// free(prompt);

			/*
			// TEST EXIT (CHAR **)
			//exit_builtin(ft_split(cmd_list[0].cmd, ' '));

			// TEST ECHO (CHAR *)
			echo_builtin(cmd_list[0].cmd);

			// TEST ENV
			//env_builtin(&mini_env, cmd_list[0].cmd);

			// TEST EXPORT (mini_env, char *)
			//export_builtin(&mini_env, cmd_list[0].cmd);

			// TEST PWD
			//pwd_builtin();

			// TEST UNSET
			//unset_builtin(&mini_env, cmd_list[0].cmd);

			// TEST CD
			//cd_builtin(&mini_env, ft_split(cmd_list[0].cmd, ' '));
			*/
		}
		else if (!prompt)
		{
			printf("exit\n");
			exit_status = 0;
			break ;
		}
	}
	exit(exit_status);
}
