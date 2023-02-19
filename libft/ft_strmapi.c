/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:46:53 by ranki             #+#    #+#             */
/*   Updated: 2022/11/12 08:23:17 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	i = ft_strlen(s);
	cpy = ft_calloc(sizeof(char), (i + 1));
	if (cpy == NULL)
		return (NULL);
	cpy[i] = '\0';
	while (j < i)
	{
		cpy[j] = f(j, s[j]);
		j++;
	}
	return (cpy);
}
