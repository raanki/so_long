/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:56:58 by ranki             #+#    #+#             */
/*   Updated: 2023/02/19 17:06:00 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_line(int fd, t_map *game)
{
	int		nb_line;
	char	*buffer;

	nb_line = 0;
	game->map_line = NULL;
	buffer = get_next_line(fd);
	while (buffer != 0)
	{
		nb_line += 1;
		game->map_line = ft_strjoin((game->map_line), buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	free(buffer);
	game->nb_line = nb_line;
	game->map = ft_split(game->map_line, '\n');
	return (nb_line);
}

int	check_carac(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] != '0' && map[i] != '1' && map[i] != 'C'
			&& map[i] != 'E' && map[i] != 'P' && map[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_only_one(t_map *game)
{
	int	count_exit;
	int	count_item;
	int	count_start;
	int	i;

	count_exit = 0;
	count_item = 0;
	count_start = 0;
	i = 0;
	while (game->map_line[i] != '\0')
	{
		if (game->map_line[i] == 'E')
			count_exit++;
		else if (game->map_line[i] == 'C')
			count_item++;
		else if (game->map_line[i] == 'P')
			count_start++;
		i++;
	}
	if (count_exit != 1 || count_item <= 1 || count_start != 1)
		return (0);
	game->nb_item = count_item;
	return (1);
}

int	game_ini(t_map *game)
{
	game->img = malloc (sizeof(t_ptr_img));
	game->img->lawn = malloc(sizeof(t_img_data));
	game->img->pipe = malloc(sizeof(t_img_data));
	game->img->coin = malloc(sizeof(t_img_data));
	game->img->brick = malloc(sizeof(t_img_data));
	game->player = malloc(sizeof(t_player));
	game->player->down = malloc(sizeof(t_img_data));
	game->player->up = malloc(sizeof(t_img_data));
	game->player->right = malloc(sizeof(t_img_data));
	game->player->left = malloc(sizeof(t_img_data));
	game->map = NULL;
	game->nb_moov = 0;
}
