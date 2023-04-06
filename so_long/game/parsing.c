/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:21:38 by ranki             #+#    #+#             */
/*   Updated: 2023/03/31 10:23:59 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_win_size(t_map *game)
{
	game->size_win_x = game->size_img * game->size_line;
	game->size_win_y = game->size_img * game->nb_line;
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->size_win_x, game->size_win_y, "So_long");
}

void	put_img(t_map *game, void *ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, ptr,
		x * game->size_img, y * game->size_img);
}

void	place_img(t_map *game, int x, int y)
{
	if (game->map[y][x] == '0')
		put_img(game, game->img->lawn->ptr, x, y);
	else if (game->map[y][x] == '1')
		put_img(game, game->img->brick->ptr, x, y);
	else if (game->map[y][x] == 'E')
		put_img(game, game->img->pipe->ptr, x, y);
	else if (game->map[y][x] == 'C')
		put_img(game, game->img->coin->ptr, x, y);
	else if (game->map[y][x] == 'P')
	{
		put_img(game, game->player->right->ptr, x, y);
		game->player->pos_x = x * game->size_img;
		game->player->pos_y = y * game->size_img;
	}
}

void	parsing_game(t_map *game)
{
	int	x;
	int	y;

	y = 0;
	file_to_image(game);
	find_win_size(game);
	while (y < (game->nb_line))
	{
		x = 0;
		while (x < (game->size_line))
		{
			place_img(game, x, y);
			x++;
		}
		y++;
	}
}
