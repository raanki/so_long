/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:08:53 by ranki             #+#    #+#             */
/*   Updated: 2023/04/06 10:40:29 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_max_size(t_map *game)
{
	if (game->nb_line > 43)
		return (0);
	if (game->size_line > 79)
		return (0);
	return (1);
}

void	ft_norm(t_map *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		free_all(game);
		write(2, "Error\nMLX can't init\n", 21);
		exit(EXIT_FAILURE);
	}
	parsing_game(game);
	mlx_hook(game->win_ptr, 2, 1L << 0, &handle_keypress, game);
	mlx_hook(game->win_ptr, 17, 1L << 17, &close_window, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_map	game;

	if (argc == 2 && check_arg(argv, &game) == 1)
	{
		if (check_all(&game) == 0)
		{
			write(2, "Error\nThe map is invalid\n", 25);
			exit(EXIT_FAILURE);
		}
		game_ini(&game);
		find_coin(&game);
		if (!access_coin(&game))
		{
			write(2, "Error\nThe map is complete but impossible\n", 41);
			free_all(&game);
			exit(EXIT_FAILURE);
		}
		ft_norm(&game);
	}
	else
		write(2, "Error\nYou have to put a valid name map in argument\n", 51);
}
