/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:28:03 by thenry            #+#    #+#             */
/*   Updated: 2023/10/17 17:28:39 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h> // INT_MAX
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/wait.h>

//------------------- STRUCT TOKEN TIBO ----------------//

extern int				exit_status;

// lower case letter
// UPPER CASE LETTER
// numeric
// space character ' '
// tab character "	" (\t)
// '\n'
// -
// ;
// ''
// ""
// (
// )
// &
// $
// |
// < (redirect the input)
// > (it does redirect the output)
// escape character '\'
// '\0'
// other char / wrong char

enum					e_char_type
{
	LALPHA,
	UALPHA,
	NUM,
	FTSPACE,
	FTTAB,
	FTNEWLINE,
	DASH,
	SEMICOL,
	SQUOTE,
	DQUOTE,
	OPARENT,
	CPARENT,
	AMPERSAND,
	DOLLAR,
	PIPE,
	REDIRIN,
	REDIROUT,
	ESCAPE,
	EOL,
	OTHER
};

enum					e_token_type
{
	WORD,
	LESS,
	DLESS,
	GREAT,
	DGREAT,
	SPIPE
};

typedef struct s_first_lst
{
	char				c;
	char				cs[2];
	int					type;
	struct s_first_lst	*next;
}						t_first_lst;

typedef struct s_second_lst
{
	char				*token;
	int					token_type;
	struct s_second_lst	*next;
}						t_second_lst;

typedef struct s_data
{
	int					**pipe;
	int					ncmd;
}						t_data;

typedef struct s_mini
{
	char				*var;
	struct s_mini		*next;
}						t_mini;

typedef struct s_cmds
{
	char				*cmd;
	char				*path;
	int					infile;
	int					outfile;
	t_data				*data;
	t_mini				*mini_env;
}						t_cmds;


// FUNCTIONS

int						ft_error(char *str);
int						ft_space(char c);
int						ft_is_quotes(char c);
int						ft_is_sep(char c);
int						bool_history(char *prompt);

// SIGNALS
void					handle(int signal);
void					init_signals(void);

// TOKENISE FL
t_first_lst				*ft_lst_last(t_first_lst *a);
t_first_lst				*ft_lst_new(char character, int in_quotes);
void					ft_lst_add_back(t_first_lst **a, t_first_lst *new);
t_first_lst				*fill_list_tmp(char *prompt);
void					print_lst(t_first_lst *list);

// TOKENISE FL UTILS
int						get_type(char c);
int						ft_space(char c);
int						ft_is_quotes(char c);
int						ft_is_sep(char c);

// CREATE CMDS
int						count_cmd(t_second_lst *sl);
void					print_cmd_list(t_cmds *cmd_list, t_second_lst *sl);
int						init_cmds(t_cmds *cmd_list, int nbc);
t_cmds					*find_cmds(t_cmds *cmd_list, t_second_lst *sl);
t_cmds					*create_cmds(t_second_lst *sl);

// TOKENISE SL
t_second_lst			*ft_second_lst_last(t_second_lst *a);
t_second_lst			*ft_second_lst_new(char *tok, int tok_type);
void					ft_second_lst_add_back(t_second_lst **a,
							t_second_lst *new);
int						ft_is_op(char c);
t_second_lst			*fill_second_list(t_first_lst *first_list);
void					print_second_lst(t_second_lst *list);

// UTILS
int						ft_strcmp(const char *s1, const char *s2);
int						ft_iscaps(char c);
char					*ft_strncpy(char *dest, char *src, int n);

// CLEAN SL
char					*ft_remove_quotes(char *token);
t_second_lst			*clean_second_list(t_second_lst *second_list,
							t_mini *mini_env);
int						ft_crap_operator(char *token);

// EXPANSION
char					*new_var(char *var);
char					*get_var(char *var, t_mini *mini_env, int *i);
char					*get_ceejay(char *c);
char					*full_expanded_token(char *token, t_mini *mini_env,
							int *i);

// HANDLE QUOTES
int						ft_unclosed_singleq(char *token);
int						ft_unclosed_doubleq(char *token);
char					*ft_quotes(char *token, t_mini *mini_env);

// FREE
void					ft_lst_clear_fl(t_first_lst **list);
void					ft_lst_clear_sl(t_second_lst **list);

// EXIT BUILTIN
int						is_numeric(char *str);
int						exit_builtin(char **cmds);

// ECHO BUILTIN
int						echo_builtin(char *cmds);

// GET_ENV
t_mini					*get_mini_env(char **env);
void					print_env(t_mini *mini);
t_mini					*ft_mini_last(t_mini *a);
t_mini					*ft_mini_new(char *var);
void					ft_mini_add_back(t_mini **a, t_mini *new);

// ENV BUILTIN
int						env_builtin(t_mini **mini_env, char *cmds);

// EXPORT BUILTIN
int						export_builtin(t_mini **mini_env, char *cmds);

// PWD BUILTIN
int						pwd_builtin(void);

// UNSET BUILTIN
int						unset_builtin(t_mini **mini_env, char *cmds);
void					delete_var(t_mini *mini_env, char *var);

// CD BUILTIN
int						cd_builtin(t_mini **mini_env, char **cmds);

// EXEC
int		Xcution(t_cmds **cmd_list, t_data *data);

void	ft_close_all(t_cmds **data_exec, t_data *data);
char	*ft_path_bin(char *cmd, t_mini *mini_env);
char	**ft_split_dos(char *s, char c, char *exe);
void	ft_free_tabx2(char **str);
void	ft_free_int(t_data *data, t_cmds **data_exec, int o);
void	ft_first_pipe(t_cmds *data_exec, int i, t_data *data);
void	ft_inter_pipe(t_cmds *data_exec, int i, t_data *data);
void	ft_last_pipe(t_cmds *data_exec, int i, t_data *data);
void	put_env(t_cmds **data_exec, t_data *data, t_mini *mini_env);
void	ft_close_fd(int *fd);
int		ft_verif_space(char *str);
void	ft_free_list(char **father);
char	*ft_strjoin_two(char const *s1, char const *s2);
void	exec(t_cmds **data_exec, t_data *data, t_mini *mini_env);
void	one_pipe(t_cmds *data_exec);
void	exec_one(t_cmds *data_exec, int i, int read_pipe, int write_pipe);
void	exec_two(t_cmds *data_exec, int i, int read_pipe, int write_pipe);
void	here_doc(t_cmds data_exec, t_data *data);
void	exec_builtin(t_cmds **data_exec, t_mini *mini_env);
char	**make_env(t_mini *mini_env);

int     ft_error(char *str);
#endif
