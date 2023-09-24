/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:08:22 by diavolo           #+#    #+#             */
/*   Updated: 2023/09/24 15:20:36 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../minishell_Diavolo/get_next_line/get_next_line.h"
# include "../minishell_Diavolo/libft/libft.h"
# include "mini_struct.h"
# include <errno.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

void	ft_put_data_exec(t_cmds *data_exec, char **av, char **env);
int		ft_call_bonus(t_cmds *data_exec);
int		ft_make_bonus(t_cmds *data_exec);
void	ft_pipe_action(t_cmds *data_exec, int i);
void	ft_close_all(t_cmds *data_exec);
void	ft_first_pipe(t_cmds *data_exec, int i);
void	ft_inter_pipe(t_cmds *data_exec, int i);
void	ft_last_pipe(t_cmds *data_exec, int i);
void	ft_make_thing(t_cmds *data_exec, int i, int read_pipe, int write_pipe);
void	ft_make_thing_two(t_cmds *data_exec, int i, int read_pipe,
			int write_pipe);
void	ft_close_fd(int *fd);
void	ft_free_int(t_cmds *data_exec, int o);
int		ft_verif_space(char *str);
char	*ft_path_bin(char *av, char **env);
char	*ft_find_bin(char **tab, int i, int o);
char	*ft_cut_path(char *path);
char	*ft_path(char *path, char **env);
void	ft_free_tabx2(char **str);
void	read_doc(t_cmds *data_exec, char *limiter);
void	open_read_doc(t_cmds *data_exec);
char	**ft_split_dos(char *s, char c, char *exe);
int		ft_strncmph(const char *s1, const char *s2, size_t n);
void	one_pipe(t_cmds *data_exec);

#endif