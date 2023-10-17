/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenry <thenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:43:51 by thenry            #+#    #+#             */
/*   Updated: 2023/10/10 17:10:40 by thenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     ft_strcmp(const char *s1, const char *s2)
{
        size_t                  i;
        unsigned char   *st1;
        unsigned char   *st2;

        i = 0;
        st1 = (unsigned char *)s1;
        st2 = (unsigned char *)s2;
        while ((st1[i] || st2[i]))
        {
                if (st1[i] != st2[i])
                        return (st1[i] - st2[i]);
                i++;
        }
        return (0);
}

int     ft_iscaps(char c)
{
        if (c >= 65 && c <= 90)
                return (1);
        return (0);
}

char    *ft_strncpy(char *dest, char *src, int n)
{
        int     i;

        i = 0;
        while (src[i] && i < n)
        {
                dest[i] = src[i];
                i++;
        }
        while (i < n)
        {
                dest[i] = '\0';
                i++;
        }
        return (dest);
}

