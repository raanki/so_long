/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 03:53:48 by ranki             #+#    #+#             */
/*   Updated: 2023/03/22 20:55:14 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *d)
{
	int	cpt;

	cpt = 0;
	if (d == NULL )
		return (0);
	while (d && d[cpt])
		cpt++;
	return (cpt);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*fresh;
	unsigned int		i;

	if (!s)
		return (NULL);
	fresh = malloc(sizeof(char) * (len + 1));
	if (fresh == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && ((start + i) < (start + len)))
	{
		fresh[i] = s[start + i];
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}

char	*ft_strchr(const char *s, int c)
{
	int		j;
	int		result;
	char	*ptr;

	result = -1;
	if (c == '\0')
	{
		ptr = (char *)&s[ft_strlen(s)];
		result = 1;
	}
	j = 0;
	while (s[j] && result == -1)
	{
		if (c == s[j])
		{
			ptr = (char *)&s[j];
			result = 1;
		}
		j++;
	}
	if (result == -1)
		return (NULL);
	else
		return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*fresh;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (fresh == NULL)
		return (NULL);
	i = -1;
	while (s1 != NULL && s1[++i])
		fresh[i] = s1[i];
	if (ft_strlen(s1) == 0)
		i++;
	j = -1;
	while (s2 != NULL && s2[++j])
	{
		fresh[i] = s2[j];
		i++;
	}
	if (ft_strlen(s2) == 0)
		i++;
	fresh[i] = '\0';
	free(s1);
	return (fresh);
}
