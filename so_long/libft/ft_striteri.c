/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:09:42 by ranki             #+#    #+#             */
/*   Updated: 2022/11/12 08:19:00 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	j;
	int	len;

	len = ft_strlen(s);
	j = 0;
	while (j < len)
	{
		f(j, &s[j]);
		j++;
	}
}
