/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:28:11 by ranki             #+#    #+#             */
/*   Updated: 2022/11/16 08:24:15 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static int	ft_check(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count_before(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && (ft_check(s1[i], set) == 1))
		i++;
	return (i);
}

static int	ft_count_after(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1);
	while (i > 0 && (ft_check(s1[i - 1], set) == 1))
		i--;
	return (ft_strlen(s1) - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned long	cpt;
	char			*cpy;
	unsigned long	i;
	unsigned long	j;

	cpy = NULL;
	cpt = 0;
	i = 0;
	if (s1 == NULL)
		return (0);
	if (set == NULL )
		return (ft_strdup(s1));
	j = 0;
	cpt = ft_count_after (s1, set) + ft_count_before(s1, set);
	if (cpt > ft_strlen(s1))
		return (ft_strdup("\0"));
	cpy = ft_calloc(sizeof(char), (ft_strlen(s1) - cpt) + 1);
	if (cpy == NULL)
		return (NULL);
	i = ft_count_before(s1, set);
	while (i < (ft_strlen(s1) - ft_count_after(s1, set)))
		cpy[j++] = s1[i++];
	cpy[j] = '\0';
	return (cpy);
}
