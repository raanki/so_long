/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moov.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:11:02 by ranki             #+#    #+#             */
/*   Updated: 2023/03/27 10:55:40 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	key_w(int keysym, t_map *game)
{
	if (game->map[(game->player->pos_y - game->size_img) / game->size_img]
		[(game->player->pos_x) / game->size_img] != '1'
		&& allow_exit(keysym, game, game->player->pos_y
			- game->size_img, game->player->pos_x) == 1)
	{
		game->player->pos_y -= game->size_img;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img->lawn->ptr, game->player->pos_x, game->player->pos_y
			+ game->size_img);
		ft_printf("Score : %d\n", ++(game->nb_moov));
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player->up->ptr, game->player->pos_x, game->player->pos_y);
}

void	key_a(int keysym, t_map *game)
{
	if (game->map[(game->player->pos_y) / game->size_img]
		[(game->player->pos_x - game->size_img) / game->size_img] != '1'
		&& allow_exit(keysym, game, game->player->pos_y, game->player->pos_x
			- game->size_img) == 1)
	{
		game->player->pos_x -= game->size_img;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img->lawn->ptr, game->player->pos_x + game->size_img,
			game->player->pos_y);
		ft_printf("Score : %d\n", ++(game->nb_moov));
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player->left->ptr,
		game->player->pos_x, game->player->pos_y);
}

void	key_s(int keysym, t_map *game)
{
	if (game->map[(game->player->pos_y + game->size_img) / game->size_img]
		[(game->player->pos_x) / game->size_img] != '1'
		&& allow_exit(keysym, game, game->player->pos_y + game->size_img,
			game->player->pos_x) == 1)
	{
		game->player->pos_y += game->size_img;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img->lawn->ptr, game->player->pos_x,
			game->player->pos_y - game->size_img);
		ft_printf("Score : %d\n", ++(game->nb_moov));
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player->down->ptr, game->player->pos_x,
		game->player->pos_y);
}

void	key_d(int keysym, t_map *game)
{
	if (game->map[(game->player->pos_y) / game->size_img]
		[(game->player->pos_x + game->size_img) / game->size_img] != '1'
		&& allow_exit(keysym, game, game->player->pos_y,
			game->player->pos_x + game->size_img) == 1)
	{
		game->player->pos_x += game->size_img;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img->lawn->ptr, game->player->pos_x - game->size_img,
			game->player->pos_y);
		ft_printf("Score : %d\n", ++(game->nb_moov));
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player->right->ptr, game->player->pos_x, game->player->pos_y);
}
