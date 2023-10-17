/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 23:13:37 by thenry            #+#    #+#             */
/*   Updated: 2023/10/13 17:23:48 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(t_mini **mini_env, char *var)
{
	t_mini	*tmp;

	tmp = *mini_env;
	while (tmp)
	{
		if (ft_strncmp(tmp->var, var, ft_strlen(var)) == 0)
			return (tmp->var + ft_strlen(var));
		tmp = tmp->next;
	}
	return (NULL);
}

int	switch_dir(t_mini **mini_env, char *old, char *pwd)
{
	unset_builtin(mini_env, "unset OLDPWD");
	export_builtin(mini_env, ft_strjoin("export OLDPWD=", old));
	unset_builtin(mini_env, "unset PWD");
	export_builtin(mini_env, ft_strjoin("export PWD=", pwd));
	return (0);
}

int	cd_old(t_mini **mini_env)
{
	char	*old;
	char	*pwd;

	old = get_env(mini_env, "OLDPWD=");
	pwd = get_env(mini_env, "PWD=");
	if (!old)
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
		exit_status = 1;
		return (exit_status);
	}
	if (chdir(old))
	{
		ft_putstr_fd("minishell: cd: error\n", 2);
		exit_status = 1;
		return (exit_status);
	}
	ft_putstr_fd(old, 1);
	ft_putstr_fd("\n", 1);
	switch_dir(mini_env, pwd, old);
	exit_status = 0;
	return (exit_status);
}

int	cd_home(t_mini **mini_env)
{
	char	*pwd;
	char	*home;

	pwd = get_env(mini_env, "PWD=");
	home = get_env(mini_env, "HOME=");
	if (!home)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		exit_status = 1;
		return (exit_status);
	}
	if (chdir(home))
	{
		ft_putstr_fd("minishell: cd: error\n", 2);
		exit_status = 1;
		return (exit_status);
	}
	switch_dir(mini_env, pwd, home);
	exit_status = 0;
	return (exit_status);
}

int	cd_path(t_mini **mini_env, char *path)
{
	char	*pwd;
	char	*tmp;

	pwd = getcwd(NULL, 0);
	if (chdir(path))
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit_status = 1;
		return (exit_status);
	}
	tmp = getcwd(NULL, 0);
	switch_dir(mini_env, pwd, tmp);
	free(pwd);
	free(tmp);
	exit_status = 0;
	return (exit_status);
}

int	cd_builtin(t_mini **mini_env, char **cmds)
{
	char	*path;

	if (cmds[0] && ft_strcmp(cmds[0], "cd") == 0 && !cmds[1])
		return (cd_home(mini_env));
	else if (cmds[0] && ft_strcmp(cmds[0], "cd") == 0 && cmds[1])
	{
		path = cmds[1];
		if (ft_strncmp(path, "-", ft_strlen(path)) == 0)
			return (cd_old(mini_env));
		else if (ft_strncmp(path, "~", ft_strlen(path)) == 0)
			return (cd_home(mini_env));
		else
			return (cd_path(mini_env, path));
	}
	else if (cmds[1] && cmds[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		exit_status = 1;
		return (exit_status);
	}
	return (exit_status);
}
