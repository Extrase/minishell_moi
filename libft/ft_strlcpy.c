/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:10:44 by mderkaou          #+#    #+#             */
/*   Updated: 2022/11/19 16:19:02 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dst == 0 || src == 0)
		return (0);
	if (size > 0)
	{
		--size;
		while (src[i] != '\0' && size != 0)
		{
			dst[i] = src[i];
			i++;
			size--;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

/*int	main()
{
	const char	src[] = "Tah lewandoski";
	char		dest[] = "";
	const char      src2[] = "Tah lewandoski";
	char		dest2[] = "";
	int	r = ft_strlcpy(dest, src, sizeof(src));

	printf("%s\n", dest);
	printf("%d\n", r);
	r = strlcpy(dest2, src2, sizeof(src));
	printf("%s\n", dest2);
	printf("%d", r);
}*/
