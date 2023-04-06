/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:01:42 by ranki             #+#    #+#             */
/*   Updated: 2022/11/19 19:04:07 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*cpy;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if ((nmemb * size) < size)
		return (NULL);
	cpy = (void *) malloc(size * nmemb);
	if (cpy == NULL)
		return (NULL);
	ft_bzero(cpy, (nmemb * size));
	return (cpy);
}
