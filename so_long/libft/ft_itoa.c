/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:38:00 by ranki             #+#    #+#             */
/*   Updated: 2022/11/12 10:48:55 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		stop;

	stop = 0;
	len = ft_size(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	s = malloc(sizeof(char) * (ft_size(n) + 1));
	if (s == NULL)
		return (s);
	if (n < 0)
	{
		s[stop++] = '-';
		n *= -1;
	}
	s[len] = '\0';
	while (stop < len)
	{
		s[--len] = n % 10 + '0';
		n = n / 10;
	}
	return (s);
}
