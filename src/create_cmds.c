/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:17:11 by thenry            #+#    #+#             */
/*   Updated: 2023/10/13 17:32:39 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_cmd(t_second_lst *sl)
{
	int				i;
	t_second_lst	*tmp;

	i = 1;
	tmp = sl;
	while (tmp)
	{
		if (tmp->token_type == SPIPE)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void	print_cmd_list(t_cmds *cmd_list, t_second_lst *sl)
{
	t_cmds	*tmp;
	int		i;

	tmp = cmd_list;
	i = 0;
	while (i < count_cmd(sl))
	{
		printf("COMMAND %d\n", i);
		printf("        full cmd: %s\n", tmp[i].cmd);
		printf("        full path: %s\n", tmp[i].path);
		printf("        infile: %d\n", tmp[i].infile);
		printf("        outfile: %d\n", tmp[i].outfile);
		printf("---------------------------------\n");
		i++;
	}
}

int	init_cmds(t_cmds *cmd_list, int nbc)
{
	int	i;

	i = 0;
	(void)cmd_list;
	while (i < nbc)
	{
		cmd_list[i].cmd = NULL;
		cmd_list[i].path = NULL;
		cmd_list[i].infile = STDIN_FILENO;
		cmd_list[i].outfile = STDOUT_FILENO;
		i++;
	}
	return (0);
}

t_cmds	*find_cmds(t_cmds *cmd_list, t_second_lst *sl)
{
	t_second_lst	*tmp;
	int				i;

	tmp = sl;
	i = 0;
	while (tmp)
	{
		if (tmp->token_type == LESS && tmp->next
			&& tmp->next->token_type == WORD)
		{
			cmd_list[i].infile = open(tmp->next->token, O_RDONLY);
			tmp = tmp->next->next;
		}
		else if (tmp->token_type == DLESS && tmp->next
				&& tmp->next->token_type == WORD)
		{
			cmd_list[i].infile = INT_MAX;
			tmp = tmp->next->next;
		}
		else if (tmp->token_type == GREAT && tmp->next
				&& tmp->next->token_type == WORD)
		{
			cmd_list[i].outfile = open(tmp->next->token,
					O_CREAT | O_WRONLY | O_TRUNC, 0777);
			tmp = tmp->next->next;
		}
		else if (tmp->token_type == DGREAT && tmp->next
				&& tmp->next->token_type == WORD)
		{
			cmd_list[i].outfile = open(tmp->next->token,
					O_CREAT | O_WRONLY | O_APPEND, 0777);
			tmp = tmp->next->next;
		}
		else if (ft_strcmp(tmp->token, "export") == 0 && tmp->next
				&& tmp->next->token_type == WORD)
		{
			if (!cmd_list[i].cmd)
			{
				cmd_list[i].cmd = tmp->token;
				while (tmp->next)
				{
					if (ft_strchr(tmp->next->token, '='))
						break ;
					else
						tmp = tmp->next;
				}
				if (tmp->next)
				{
					cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, " ");
					cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd,
							tmp->next->token);
				}
				cmd_list[i].path = "{EXPORT BUILTIN}";
				while (tmp && tmp->token_type != SPIPE)
				{
					tmp = tmp->next;
				}
			}
			else
			{
				cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, " ");
				cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, tmp->token);
				tmp = tmp->next;
			}
		}
		else if (ft_strcmp(tmp->token, "export") == 0 && (!tmp->next
					|| tmp->next->token_type == SPIPE))
		{
			if (!cmd_list[i].cmd)
			{
				cmd_list[i].cmd = tmp->token;
				cmd_list[i].path = "{EXPORT BUILTIN}";
				tmp = tmp->next;
			}
		}
		else if (ft_strcmp(tmp->token, "pwd") == 0)
		{
			if (!cmd_list[i].cmd)
			{
				cmd_list[i].cmd = tmp->token;
				cmd_list[i].path = "{PWD BUILTIN}";
				while (tmp && tmp->token_type != SPIPE)
					tmp = tmp->next;
			}
			else
			{
				cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, " ");
				cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, tmp->token);
				tmp = tmp->next;
			}
		}
		else if (ft_strcmp(tmp->token, "unset") == 0 && tmp->next
				&& tmp->next->token_type == WORD)
		{
			if (!cmd_list[i].cmd)
			{
				cmd_list[i].cmd = tmp->token;
				if (tmp->next)
				{
					cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, " ");
					cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd,
							tmp->next->token);
				}
				cmd_list[i].path = "{UNSET BUILTIN}";
				while (tmp && tmp->token_type != SPIPE)
				{
					tmp = tmp->next;
				}
			}
			else
			{
				cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, " ");
				cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, tmp->token);
				tmp = tmp->next;
			}
		}
		else if (ft_strcmp(tmp->token, "unset") == 0 && (!tmp->next
					|| tmp->next->token_type == SPIPE))
		{
			if (!cmd_list[i].cmd)
			{
				cmd_list[i].cmd = tmp->token;
				cmd_list[i].path = "{UNSET BUILTIN}";
				tmp = tmp->next;
			}
			else
			{
				cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, " ");
				cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, tmp->token);
				tmp = tmp->next;
			}
		}
		else if (ft_strcmp(tmp->token, "env") == 0 && (!tmp->next
					|| tmp->next->token_type == SPIPE))
		{
			if (!cmd_list[i].cmd)
			{
				cmd_list[i].cmd = tmp->token;
				cmd_list[i].path = "{ENV BUILTIN}";
				tmp = tmp->next;
			}
			else
			{
				cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, " ");
				cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, tmp->token);
				tmp = tmp->next;
			}
		}
		else if (ft_strcmp(tmp->token, "env") == 0 && tmp->next
				&& tmp->next->token_type == WORD)
		{
			if (!cmd_list[i].cmd)
			{
				cmd_list[i].cmd = tmp->token;
				if (tmp->next)
				{
					cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, " ");
					cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd,
							tmp->next->token);
				}
				cmd_list[i].path = "{ENV BUILTIN}";
				while (tmp && tmp->token_type != SPIPE)
				{
					tmp = tmp->next;
				}
			}
			else
			{
				cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, " ");
				cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, tmp->token);
				tmp = tmp->next;
			}
		}
		else if (ft_strcmp(tmp->token, "echo") == 0)
		{
			if (!cmd_list[i].cmd)
			{
				cmd_list[i].cmd = tmp->token;
				cmd_list[i].path = "{ECHO BUILTIN}";
				tmp = tmp->next;
			}
			else
			{
				cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, " ");
				cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, tmp->token);
				tmp = tmp->next;
			}
		}
		else if (ft_strcmp(tmp->token, "cd") == 0)
		{
			if (!cmd_list[i].cmd)
			{
				cmd_list[i].cmd = tmp->token;
				cmd_list[i].path = "{CD BUILTIN}";
				tmp = tmp->next;
			}
			else
			{
				cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, " ");
				cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, tmp->token);
				tmp = tmp->next;
			}
		}
		else if (tmp->token_type == WORD)
		{
			if (!cmd_list[i].cmd)
				cmd_list[i].cmd = tmp->token;
			else
			{
				cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, " ");
				cmd_list[i].cmd = ft_strjoin(cmd_list[i].cmd, tmp->token);
			}
			tmp = tmp->next;
		}
		else if (tmp->token_type == SPIPE)
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (cmd_list);
}

t_cmds	*create_cmds(t_second_lst *sl)
{
	int		nbc;
	t_cmds	*cmd_list;

	nbc = count_cmd(sl);
	cmd_list = malloc(sizeof(t_cmds) * nbc);
	if (!cmd_list)
	{
		ft_error("Error: malloc cmds\n");
		return (NULL);
	}
	if (init_cmds(cmd_list, nbc) == -1)
	{
		ft_error("Error: init cmds\n");
		return (NULL);
	}
	cmd_list = find_cmds(cmd_list, sl);
	return (cmd_list);
}
