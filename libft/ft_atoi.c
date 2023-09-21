/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:44:03 by mderkaou          #+#    #+#             */
/*   Updated: 2023/02/08 18:51:29 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi(const char *nptr)
{
	long long int	i;
	long long int	nb;
	long long int	count;

	i = 0;
	nb = 0;
	count = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
		++i;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			++count;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	if (count % 2 != 0)
		return (-nb);
	return (nb);
}

/*int	main(int ac, const char *av[])
  {
  if (ac > 1)
  {
  printf("%d\n", ft_atoi(av[1]));
  printf("%d", atoi(av[1]));
  }
  }*/
