/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:30:18 by mderkaou          #+#    #+#             */
/*   Updated: 2023/05/12 23:07:21 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*copy;

	i = ft_strlene(((char *)s1));
	j = ft_strlene(((char *)s2));
	copy = malloc(sizeof(*s1) * (i + j) + 2);
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = ((char *)s1)[i];
		++i;
	}
	j = 0;
	copy[i++] = '/';
	while (s2[j] && s2[j + 1] != '-')
	{
		copy[i] = ((char *)s2)[j];
		++j;
		++i;
	}
	copy[i] = '\0';
	return (copy);
}

/*int	main()
{
	char const	s1[] = "Ce qui compte, c'est pas d'avoir beaucoup de temps";
	char const	s2[] = " c'est de savoir s'en servir";
	char	*test;

	test = ft_strjoin(s1, s2);
	printf("%s\n", test);
}*/
