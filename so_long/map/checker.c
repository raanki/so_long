/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:09:35 by ranki             #+#    #+#             */
/*   Updated: 2023/03/31 10:25:38 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	size_line(char *line, t_map *game)
{
	int	i;
	int	size_line;

	size_line = 0;
	i = 0;
	while (line != NULL && line[i] != '\n' && line[i] != '\0')
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
	while (line != NULL && line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1')
		{
			return (0);
		}
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

int	check_all(t_map *game)
{
	game->map = NULL;
	if (count_line(game->fd, game) < 0)
	{
		free(game->map_line);
		free_array(game);
		return (0);
	}
	if (size_line(game->map_line, game)
		&& check_sizeline(game) && check_carac(game->map_line)
		&& check_only_one(game)
		&& check_border(game->map, game->nb_line, game)
		&& check_max_size(game))
		return (1);
	free(game->map_line);
	free_array(game);
	return (0);
}
