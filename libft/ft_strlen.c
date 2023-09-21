/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:22:29 by mderkaou          #+#    #+#             */
/*   Updated: 2023/05/27 20:50:35 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlene(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strslen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	return (i);
}

void	ft_free_list(char **father)
{
	int	i;

	i = 0;
	if (father)
	{
		if (father[i])
		{
			while (father[i])
			{
				free(father[i]);
				i++;
			}
		}
		free(father);
	}
	return ;
}
/*int	main(void)
{
	printf("%ld\n", ft_strlen(""));
	printf("%ld\n", strlen(""));
}*/
