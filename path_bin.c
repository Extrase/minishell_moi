/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:38:53 by diavolo           #+#    #+#             */
/*   Updated: 2023/09/21 16:45:04 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_path_bin(char *av, char **env)
{
	int		i;
	int		o;
	char	**tab;
	char	*path;

	path = NULL;
	if (access(av, F_OK | X_OK) == 0)
		return (ft_strdup(av));
	path = ft_path(path, env);
	if (path == NULL)
		return (NULL);
	i = 0;
	path = ft_cut_path(path);
	tab = ft_split_dos(path, ':', av);
	if (tab == NULL)
		return (NULL);
	o = 0;
	path = ft_find_bin(tab, i, o);
	ft_free_tabx2(tab);
	if (path == NULL)
		return (NULL);
	return (path);
}

char	*ft_find_bin(char **tab, int i, int o)
{
	char	*str;

	str = NULL;
	while (tab[i])
	{
		o = access(tab[i], F_OK | X_OK);
		if (o == 0)
		{
			o = ft_strlen(tab[i]);
			str = malloc(sizeof(char) * (o + 1));
			ft_strlcpy(str, tab[i], (o + 1));
			return (str);
		}
		i++;
	}
	return (NULL);
}

char	*ft_cut_path(char *path)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		path++;
		i++;
	}
	return (path);
}

char	*ft_path(char *path, char **env)
{
	int	i;
	int	j;

	j = 0;
	while (env[j])
	{
		i = 0;
		while (env[j][i])
		{
			if (ft_strncmp(env[j], "PATH=", 5) == 0)
			{
				path = env[j];
				return (path);
			}
			i++;
		}
		j++;
	}
	return (NULL);
}
