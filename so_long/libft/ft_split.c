/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:18:03 by ranki             #+#    #+#             */
/*   Updated: 2022/11/12 11:18:47 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(const char c, char set)
{
	return (c == set);
}

static int	ft_size(const char *s, char set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		if (ft_isset(*(s + j), set) == 1)
			j++;
		else
		{
			i++;
			while (s[j] != '\0' && ft_isset(*(s + j), set) == 0)
				j++;
		}
	}
	return (i);
}

static char	**ft_split_aux(char const *s, char set, char **cpy, int len)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] && j < ft_size(s, set))
	{
		while (s[i] != '\0' && ft_isset(s[i], set) == 1)
			i++;
		while (s[i] != '\0' && ft_isset(s[i], set) == 0)
		{
			len++;
			i++;
		}
		cpy[j] = ft_calloc(sizeof(char), (len + 1));
		if (cpy[j] == NULL)
			return (NULL);
		k = 0;
		while (len != 0)
			cpy[j][k++] = s[i - len--];
		cpy[++j] = 0;
	}
	return (cpy);
}

char	**ft_split(char const *s, char set)
{
	char	**cpy;

	cpy = ft_calloc(sizeof(char *), (ft_size(s, set) + 1));
	if (cpy == NULL)
		return (NULL);
	return (ft_split_aux(s, set, cpy, 0));
}
