/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:35:15 by ranki             #+#    #+#             */
/*   Updated: 2023/04/02 14:35:17 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	game_ini(t_map *game)
{
	game->win_ptr = NULL;
	ft_gameini0(game);
	game->player->down = malloc(sizeof(t_img_data));
	ft_checkmalloc(game->player->down, game);
	game->player->up = malloc(sizeof(t_img_data));
	ft_checkmalloc(game->player->up, game);
	game->player->right = malloc(sizeof(t_img_data));
	ft_checkmalloc(game->player->right, game);
	game->player->left = malloc(sizeof(t_img_data));
	ft_checkmalloc(game->player->left, game);
	game->nb_moov = 0;
	game->player->left->ptr = NULL;
	game->player->up->ptr = NULL;
	game->player->down->ptr = NULL;
	game->player->right->ptr = NULL;
	game->img->lawn->ptr = NULL;
	game->img->pipe->ptr = NULL;
	game->img->coin->ptr = NULL;
	game->img->brick->ptr = NULL;
	return (1);
}

int	ft_visited(t_map *all, t_pos **visited, int x, int y)
{
	char	temp;
	t_pos	*current;

	temp = all->map[y][x];
	all->map[y][x] = 'V';
	current = *visited;
	while (current)
	{
		if (current->x == x && current->y == y && current != *visited)
		{
			all->map[y][x] = temp;
			return (0);
		}
		current = current->next;
	}
	return (1);
}
