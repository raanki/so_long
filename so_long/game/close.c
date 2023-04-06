/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:20:03 by ranki             #+#    #+#             */
/*   Updated: 2023/03/31 10:24:08 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	escape_key(int keysym, t_map *game)
{
	if (keysym == XK_Escape)
	{
		free_all(game);
		exit(0);
	}
	return (1);
}

int	close_window(t_map *game)
{
	free_all(game);
	exit(0);
}

void	free_all0(t_map *game)
{
	if (game->img != NULL)
	{
		if (game->img->lawn != NULL)
			free_img(game->img->lawn);
		if (game->img->brick != NULL)
			free_img(game->img->brick);
		if (game->img->pipe != NULL)
			free_img(game->img->pipe);
		if (game->img->coin != NULL)
			free_img(game->img->coin);
		free(game->img);
	}
}

void	free_all(t_map *game)
{
	free_window(game);
	if (game != NULL)
	{
		free_all0(game);
		if (game->player != NULL)
		{
			if (game->player->up != NULL)
				free_img(game->player->up);
			if (game->player->down != NULL)
				free_img(game->player->down);
			if (game->player->left != NULL)
				free_img(game->player->left);
			if (game->player->right != NULL)
				free_img(game->player->right);
			free(game->player);
		}
	}
	free(game->map_line);
	free(game->item_row);
	free(game->item_col);
	free_array(game);
	free(game->mlx_ptr);
}
