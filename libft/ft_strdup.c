/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:35:48 by mderkaou          #+#    #+#             */
/*   Updated: 2022/11/19 16:18:55 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		i;

	i = 0;
	while (s[i])
		++i;
	copy = malloc(sizeof(char) * i + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = ((char *)s)[i];
		++i;
	}
	copy[i] = '\0';
	return (copy);
}

/*int	main()
{
	const char	str[] = "Ce qui compte, c'est pas d'avoir beaucoup de temps";
	char	*test;
	char	*test1;

	test = ft_strdup(str);
	printf("%s\n", test);
	test1 = strdup(str);
	printf("%s", test1);
}*/
