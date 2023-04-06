/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:49:33 by ranki             #+#    #+#             */
/*   Updated: 2023/03/31 13:54:49 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_pos	*create_pos(int x, int y)
{
	t_pos	*pos;

	pos = malloc(sizeof(t_pos));
	if (pos == NULL)
		return (NULL);
	pos->x = x;
	pos->y = y;
	pos->next = NULL;
	return (pos);
}

void	push_pos(t_pos **list, int x, int y)
{
	t_pos	*new_pos;

	new_pos = create_pos(x, y);
	new_pos->next = *list;
	*list = new_pos;
}

void	free_list(t_pos **list)
{
	t_pos	*current;
	t_pos	*next;

	current = *list;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*list = NULL;
}

char	**ft_copy_tab(t_map *all)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * all->nb_line);
	ft_checkmalloc(map_copy, all);
	i = 0;
	while (i < all->nb_line)
	{
		map_copy[i] = ft_strdup(all->map[i]);
		i++;
	}
	return (map_copy);
}

int	check_sizeline(t_map *all)
{
	int	i;

	i = 0;
	while (i < all->nb_line)
	{
		if (ft_strlen(all->map[i]) != all->size_line)
			return (0);
		i++;
	}
	return (1);
}
