/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:33:05 by ranki             #+#    #+#             */
/*   Updated: 2023/03/31 15:36:40 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_dfs(t_map *all, int x, int y, t_pos **visited)
{
	char	temp;

	if (x < 0 || x >= all->size_line || y < 0 || y >= all->nb_line
		|| all->map[y][x] == '1')
		return (0);
	if (all->map[y][x] == 'E')
		return (1);
	push_pos(visited, x, y);
	temp = all->map[y][x];
	if (ft_visited(all, visited, x, y) == 0)
		return (0);
	all->map[y][x] = 'V';
	if (ft_dfs(all, x, y - 1, visited)
		|| ft_dfs(all, x, y + 1, visited)
		|| ft_dfs(all, x - 1, y, visited)
		|| ft_dfs(all, x + 1, y, visited))
	{
		free_list(visited);
		return (1);
	}
	all->map[y][x] = temp;
	return (0);
}

int	ft_dfs_coin(t_map *all, int x, int y, t_pos **visited)
{
	char	temp;

	if (x < 0 || x >= all->size_line || y < 0 || y >= all->nb_line
		|| all->map[y][x] == '1' || all->map[y][x] == 'E')
		return (0);
	if (all->item_col[all->number_coin] == x && all->item_row[all->number_coin]
		== y)
		return (1);
	push_pos(visited, x, y);
	temp = all->map[y][x];
	all->map[y][x] = 'V';
	if (ft_visited(all, visited, x, y) == 0)
		return (0);
	if (ft_dfs_coin(all, x, y - 1, visited)
		|| ft_dfs_coin(all, x, y + 1, visited)
		|| ft_dfs_coin(all, x - 1, y, visited)
		|| ft_dfs_coin(all, x + 1, y, visited))
	{
		free_list(visited);
		return (1);
	}
	all->map[y][x] = temp;
	return (0);
}

int	access_coin0(t_map *all, t_pos *visited, char **copy_tab2, char **copy_tab)
{
	if (!ft_dfs_coin(all, all->player->pos_x / 32, all->player->pos_y / 32,
			&visited))
	{
		free_doublearray(copy_tab, all);
		free_doublearray(copy_tab2, all);
		free_list(&visited);
		return (0);
	}
	return (1);
}

int	access_coin1(t_map *all, t_pos *visited, char **copy_tab2, char **copy_tab)
{
	free_array(all);
	all->map = copy_tab;
	if (ft_dfs(all, all->player->pos_x / 32, all->player->pos_y / 32,
			&visited) == 0)
	{
		free_doublearray(copy_tab2, all);
		free_list(&visited);
		return (0);
	}
	return (1);
}

int	access_coin(t_map *all)
{
	int				i;
	t_pos			*visited;
	char			**copy_tab;
	char			**copy_tab2;

	copy_tab = ft_copy_tab(all);
	copy_tab2 = ft_copy_tab(all);
	visited = NULL;
	i = 0;
	while (i < all->nb_item)
	{
		all->number_coin = i++;
		if (access_coin0(all, visited, copy_tab2, copy_tab) == 0)
			return (0);
		visited = NULL;
	}
	if (access_coin1(all, visited, copy_tab2, copy_tab) == 0)
		return (0);
	free_array(all);
	all->map = copy_tab2;
	return (1);
}
