/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:25:48 by ranki             #+#    #+#             */
/*   Updated: 2022/11/19 19:46:52 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = ft_strlen(str) + 1;
	while (i)
	{
		i--;
		if (str[i] == (char)c)
			return ((char *)str + i);
	}
	return (0);
}
