/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:09:35 by ranki             #+#    #+#             */
/*   Updated: 2023/02/19 18:54:22 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	size_line(char *line, t_map *game)
{
	int	i;
	int	size_line;

	size_line = 0;
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		size_line++;
		(i)++;
	}
	game->size_line = size_line;
	return (size_line);
}

int	check_only_1(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_border(char **map, int nb_line, t_map *game)
{
	if (check_only_1(map[0]) == 0 || check_only_1(map[nb_line - 1]) == 0)
		return (0);
	while (nb_line > 0)
	{
		if (map[nb_line - 1][size_line(game->map[nb_line - 1], game) - 1] != '1'
			|| map[nb_line - 1][0] != '1')
			return (0);
		nb_line--;
	}
	return (1);
}

int	check_rectangle(t_map *game)
{
	if (game->nb_line <= game->size_line)
		return (1);
	return (0);
}

int	check_all(t_map *game)
{
	int	fd;

	fd = open ("map_files/big.ber", O_RDONLY);
	if (count_line(fd, game) && size_line(game->map_line, game)
		&& check_carac(game->map_line)
		&& check_only_one(game) && check_rectangle(game)
		&& check_border(game->map, game->nb_line, game))
	{
		find_coin(game);
		return (1);
	}
	return (0);
}
