/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:02:19 by mderkaou          #+#    #+#             */
/*   Updated: 2023/02/08 17:39:57 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57) || (c == '-'))
		return (2048);
	return (0);
}

/*int	main()
{
	printf("%d\n", ft_isdigit(50));
	printf("%d\n", isdigit(50));
}*/
