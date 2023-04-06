/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:11:49 by ranki             #+#    #+#             */
/*   Updated: 2022/11/11 08:33:21 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static size_t	ft_strlen(const char *d)
{
	size_t	cpt;

	cpt = 0;
	while (d[cpt])
		cpt++;
	return (cpt);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;

	if (start > ft_strlen(s))
	{
		cpy = malloc(sizeof(char));
		if (cpy == NULL)
			return (NULL);
		cpy[0] = '\0';
		return (cpy);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	cpy = malloc(sizeof(char) * len + 1);
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (((char *)s)[start] == '\0')
			break ;
		cpy[i++] = ((char *)s)[start++];
	}
	cpy[i] = '\0';
	return (cpy);
}
