/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:57:44 by ranki             #+#    #+#             */
/*   Updated: 2023/03/31 15:30:43 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "X11/X.h"
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include "ft_printf/ft_printf.h"

typedef struct s_img_data
{
	void	*ptr;
	int		*height;
	int		*width;
	int		*frame;
}t_img_data;

typedef struct s_ptr_img
{
	t_img_data	*lawn;
	t_img_data	*brick;
	t_img_data	*pipe;
	t_img_data	*coin;
}t_ptr_img;

typedef struct s_player
{
	int			pos_x;
	int			pos_y;
	int			orientation;
	t_img_data	*left;
	t_img_data	*right;
	t_img_data	*up;
	t_img_data	*down;
}t_player;

typedef struct s_pos
{
	int				x;
	int				y;
	struct s_pos	*next;
}t_pos;

typedef struct s_map
{
	int				*item_row;
	int				*item_col;
	int				nb_line;
	int				size_line;
	int				nb_item;
	int				pos_exit[2];
	int				size_win_x;
	int				size_win_y;
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	char			*map_line;
	t_ptr_img		*img;
	t_player		*player;
	int				nb_moov;
	int				size_img;
	t_pos			*visited;
	int				number_coin;
	int				fd;
}t_map;

int		check_max_size(t_map *game);
void	find_coin0(t_map *game, int x, int y, int *i);
int		ft_visited(t_map *all, t_pos **visited, int x, int y);
void	ft_gameini0(t_map *game);
int		game_ini(t_map *game);
void	free_doublearray(char **tab, t_map *game);
int		check_arg(char **argv, t_map *game);
void	file_to_image0(t_map *game);
t_pos	*create_pos(int x, int y);
void	ft_checkmalloc(void *ptr, t_map *all);
void	push_pos(t_pos **list, int x, int y);
char	**ft_copy_tab(t_map *all);
void	free_list(t_pos **list);
int		check_sizeline(t_map *all);
int		access_coin(t_map *all);
int		ft_dfs(t_map *all, int x, int y, t_pos **visited);
void	free_window(t_map *game);
void	free_img(t_img_data *img);
void	free_array(t_map *game);
void	game_ini_null(t_map *game);
void	free_all(t_map *game);
int		update_animation(t_map *piece);
int		size_line(char *line, t_map *game);
int		count_line(int fd, t_map *game);
int		check_carac(char *map);
int		check_only_one(t_map *game);
void	file_to_image(t_map *game);
void	parsing_game(t_map *game);
int		escape_key(int keysym, t_map *game);
int		main(int argc, char **argv);
int		close_window(t_map *game);
int		handle_keypress(int keysym, t_map *game);
void	find_coin(t_map *game);
int		check_only_one(t_map *game);
int		check_all(t_map *game);
int		check_all(t_map *game);
int		game_ini(t_map *game);
void	key_w(int keysym, t_map *game);
void	key_d(int keysym, t_map *game);
void	key_a(int keysym, t_map *game);
void	key_s(int keysym, t_map *game);
int		allow_exit(int keysym, t_map *game, int next_move_x, int next_move_y);

#endif
