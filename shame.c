/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:46:27 by diavolo           #+#    #+#             */
/*   Updated: 2023/09/21 16:46:48 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmph(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str2;

	if (ft_strlene(s1) != (ft_strlene(s2) + 1))
		return (1);
	i = 0;
	str = ((unsigned char *)s1);
	str2 = ((unsigned char *)s2);
	while (i < n)
	{
		if (str[i] != str2[i])
			return (str[i] - str2[i]);
		++i;
	}
	return (0);
}