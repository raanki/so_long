/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:08:50 by ranki             #+#    #+#             */
/*   Updated: 2022/11/16 08:17:18 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)s;
	i = 0;
	if (n < 1)
		return (NULL);
	while (i < n)
	{
		if (tmp[i] == (char)c)
		{
			return (tmp + i);
		}
		else
		{
			i++;
		}
	}
	return (NULL);
}
