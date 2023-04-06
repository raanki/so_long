/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:39:58 by ranki             #+#    #+#             */
/*   Updated: 2023/03/23 09:27:26 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	allow_exit(int keysym, t_map *game, int next_move_x, int next_move_y)
{
	(void) keysym;
	if (game->nb_item == 0 && game->map[next_move_x
			/ game->size_img][next_move_y / game->size_img] == 'E')
	{
		close_window(game);
		exit(0);
	}
	else if (game->map[next_move_x
			/ game->size_img][next_move_y / game->size_img] == 'C')
	{
		game->map[next_move_x
			/ game->size_img][next_move_y / game->size_img] = '0';
		(game->nb_item)--;
	}
	else if (game->nb_item != 0 && game->map[next_move_x
			/ game->size_img][next_move_y / game->size_img] == 'E')
		return (0);
	return (1);
}

int	handle_keypress(int keysym, t_map *game)
{
	escape_key(keysym, game);
	if (keysym == XK_w || keysym == XK_Up)
		key_w(keysym, game);
	else if (keysym == XK_a || keysym == XK_Left)
		key_a(keysym, game);
	else if (keysym == XK_s || keysym == XK_Down)
		key_s(keysym, game);
	else if (keysym == XK_d || keysym == XK_Right)
		key_d(keysym, game);
	return (1);
}

void	ft_checkmalloc(void *ptr, t_map *all)
{
	if (ptr == NULL)
	{
		free_all(all);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
