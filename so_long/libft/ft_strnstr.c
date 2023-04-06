/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:02:03 by ranki             #+#    #+#             */
/*   Updated: 2022/11/16 17:18:50 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*sa;

	i = 0;
	j = 0;
	sa = (char *)s1;
	if (s2[0] == '\0')
		return (sa);
	while (s1[i] != '\0')
	{
		while (s1[i + j] == s2[j] && s2[j] != 0
			&& (i + j < n))
		{
			j++;
		}
		if (s2[j] == '\0')
			return (sa + i);
		j = 0;
		i++;
	}
	return (NULL);
}
