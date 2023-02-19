/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:55:44 by ranki             #+#    #+#             */
/*   Updated: 2023/02/19 18:48:24 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	file_to_image(t_map *game)
{
	game->img->lawn->ptr = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/lawn.xpm", &(game->size_img), &(game->size_img));
	game->img->brick->ptr = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/Brick.xpm", &(game->size_img), &(game->size_img));
	game->img->pipe->ptr = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/pipe.xpm", &(game->size_img), &(game->size_img));
	game->img->coin->ptr = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/Gold_1.xpm", &(game->size_img), &(game->size_img));
	game->player->up->ptr = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/Up.xpm", &(game->size_img), &(game->size_img));
	game->player->down->ptr = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/Down.xpm", &(game->size_img), &(game->size_img));
	game->player->left->ptr = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/Left.xpm", &(game->size_img), &(game->size_img));
	game->player->right->ptr = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/Right.xpm", &(game->size_img), &(game->size_img));
}

void	find_coin(t_map *game)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	game->item_col = malloc(sizeof(int) * game->nb_item);
	game->item_row = malloc(sizeof(int) * game->nb_item);
	while (y < game->nb_line)
	{
		x = 0;
		while (x < game->size_line)
		{
			if (game->map[y][x] == 'C')
			{
				game->item_col[i] = x;
				game->item_row[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
}
