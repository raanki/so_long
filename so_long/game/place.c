/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:55:44 by ranki             #+#    #+#             */
/*   Updated: 2023/03/31 09:00:04 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	file_to_image(t_map *game)
{
	file_to_image0(game);
	game->player->down->ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/Down.xpm", &(game->size_img), &(game->size_img));
	ft_checkmalloc(game->player->down->ptr, game);
	game->player->left->ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/Left.xpm", &(game->size_img), &(game->size_img));
	ft_checkmalloc(game->player->left->ptr, game);
	game->player->right->ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/Right.xpm", &(game->size_img), &(game->size_img));
	ft_checkmalloc(game->player->right->ptr, game);
}

void	free_img(t_img_data *img)
{
	if (img != NULL)
		free(img);
}

void	free_window(t_map *game)
{
	if (game->mlx_ptr != NULL)
	{
		if (game->win_ptr != NULL)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		if (game->player->left->ptr != NULL)
			mlx_destroy_image(game->mlx_ptr, game->player->left->ptr);
		if (game->player->right->ptr != NULL)
			mlx_destroy_image(game->mlx_ptr, game->player->right->ptr);
		if (game->player->up->ptr != NULL)
			mlx_destroy_image(game->mlx_ptr, game->player->up->ptr);
		if (game->player->down->ptr != NULL)
			mlx_destroy_image(game->mlx_ptr, game->player->down->ptr);
		if (game->img->lawn->ptr != NULL)
			mlx_destroy_image(game->mlx_ptr, game->img->lawn->ptr);
		if (game->img->brick->ptr != NULL)
			mlx_destroy_image(game->mlx_ptr, game->img->brick->ptr);
		if (game->img->pipe->ptr != NULL)
			mlx_destroy_image(game->mlx_ptr, game->img->pipe->ptr);
		if (game->img->coin->ptr != NULL)
			mlx_destroy_image(game->mlx_ptr, game->img->coin->ptr);
		mlx_destroy_display(game->mlx_ptr);
	}
}

void	free_array(t_map *game)
{
	int	i;

	i = 0;
	if (game->map != NULL)
	{
		if (*(game->map) != NULL)
		{
			while (game->nb_line > i)
			{
				free(game->map[i]);
				i++;
			}
		}
		free(game->map);
	}
}

void	find_coin(t_map *game)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	game->item_col = malloc(sizeof(int) * game->nb_item);
	ft_checkmalloc(game->item_col, game);
	game->item_row = malloc(sizeof(int) * game->nb_item);
	ft_checkmalloc(game->item_row, game);
	while (y < game->nb_line)
	{
		x = 0;
		while (x < game->size_line)
		{
			find_coin0(game, x, y, &i);
			x++;
		}
		y++;
	}
}
