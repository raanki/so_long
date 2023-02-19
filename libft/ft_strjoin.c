/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 08:35:19 by ranki             #+#    #+#             */
/*   Updated: 2022/11/11 09:20:04 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include "stdlib.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cpy;
	int		i;
	int		y;

	cpy = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (cpy == NULL)
		return (NULL);
	ft_memcpy (cpy, s1, ft_strlen(s1));
	y = 0;
	i = ft_strlen(s1);
	while (s2[y] != '\0')
		cpy[i++] = ((char *)s2)[y++];
	cpy[i] = '\0';
	return (cpy);
}
