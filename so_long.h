#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "X11/X.h"
#include <X11/Xlib.h>
#include <X11/keysym.h>

typedef struct s_img_data
{
    void *ptr;
    int *height;
    int *width;
    int *frame;
} t_img_data;

typedef struct s_ptr_img
{
    t_img_data *lawn;
    t_img_data *brick;
    t_img_data *pipe;
    t_img_data *coin;
} t_ptr_img;

typedef struct s_player
{
    int pos_x;
    int pos_y;
    int orientation;
    t_img_data *left;
    t_img_data *right;
    t_img_data *up;
    t_img_data *down;

} t_player;



typedef struct s_map
{
    int *item_row;
    int *item_col;
    int nb_line;
    int size_line;
    int nb_item;
    int pos_exit[2];
    int size_win_x;
    int size_win_y;
    void *mlx_ptr;
    void *win_ptr;
    char **map;
    char *map_line;
    t_ptr_img *img;
    t_player *player;
    int nb_moov;
    int size_img;
} t_map;

//int update_animation(t_img_data *piece);
int size_line(char *line, t_map *game);
int count_line(int fd, t_map *game);
int check_carac(char *map);
int check_only_one(t_map *game);
void file_to_image(t_map *game);
void parsing_game(t_map *game);
int escape_key(int keysym, t_map *game);
int main(int argc, char **argv);
int close_window(t_map *game);
int handle_keypress(int keysym, t_map *game);
void find_coin(t_map *game);
int check_only_one(t_map *game);
int check_all(t_map *game);
int check_all(t_map *game);
int game_ini(t_map *game);
int bfs(int row, int col, int dest_row, int dest_col, char **grid, int num_items);

#endif