/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:52:11 by ranki             #+#    #+#             */
/*   Updated: 2023/04/01 12:52:12 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	file_to_image0(t_map *game)
{
	game->img->lawn->ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/lawn.xpm", &(game->size_img), &(game->size_img));
	ft_checkmalloc(game->img->lawn->ptr, game);
	game->img->brick->ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/Brick.xpm", &(game->size_img), &(game->size_img));
	ft_checkmalloc(game->img->brick->ptr, game);
	game->img->pipe->ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/pipe.xpm", &(game->size_img), &(game->size_img));
	ft_checkmalloc(game->img->pipe->ptr, game);
	game->img->coin->ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/Gold_1.xpm", &(game->size_img), &(game->size_img));
	ft_checkmalloc(game->img->coin->ptr, game);
	game->player->up->ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/Up.xpm", &(game->size_img), &(game->size_img));
	ft_checkmalloc(game->player->up->ptr, game);
}

void	free_doublearray(char **tab, t_map *game)
{
	int	i;

	i = 0;
	if (game->map != NULL)
	{
		if (*(game->map) != NULL)
		{
			while (game->nb_line > i)
			{
				free(tab[i]);
				i++;
			}
		}
		free(tab);
	}
}

void	find_coin0(t_map *game, int x, int y, int *i)
{
	if (game->map[y][x] == 'C')
	{
		game->item_col[*i] = x;
		game->item_row[*i] = y;
		(*i)++;
	}
	if (game->map[y][x] == 'P')
	{
		game->player->pos_x = x * 32;
		game->player->pos_y = y * 32;
	}
}
