/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:01:34 by ranki             #+#    #+#             */
/*   Updated: 2023/04/01 13:01:35 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_point(char *argv)
{
	int	i;

	i = 0;
	if (argv == NULL || argv[0] == '\0')
		return (0);
	while (argv[i] != '\0')
	{
		if (i != 0 && argv[i] == '.' && argv[i + 1] == 'b' && argv[i + 2] == 'e'
			&& argv[i + 3] == 'r' && argv[i + 4] == '\0')
			return (1);
		else
			i++;
	}
	return (0);
}

int	check_arg(char **argv, t_map *all)
{
	char	*filename;

	filename = NULL;
	if (check_point(argv[1]) == 0)
		return (0);
	filename = ft_strjoin(ft_strdup("./map_files/"), argv[1]);
	all->fd = open(filename, O_RDONLY);
	free(filename);
	if (all->fd < 0)
	{
		return (0);
	}
	return (1);
}
