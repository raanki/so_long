#include "../so_long.h"

int allow_exit(int keysym, t_map *game, int next_move_x, int next_move_y)
{
    //printf("nb_item : %d\n", game->nb_item);
    if (game->nb_item == 0 && game->map[next_move_x / game->size_img][next_move_y / game->size_img] == 'E')
    {
                mlx_destroy_window(game->mlx_ptr, game->win_ptr);
                exit(0);
        return (1);
    }
    else if (game->map[next_move_x / game->size_img][next_move_y / game->size_img] == 'C')
    {
        game->map[next_move_x / game->size_img][next_move_y / game->size_img] = '0';
        (game->nb_item)--;
    }
    else  if (game->nb_item != 0 && game->map[next_move_x / game->size_img][next_move_y / game->size_img] == 'E')
        return (0);
    return (1);
}

int handle_keypress(int keysym, t_map *game)
{
    escape_key(keysym, game);
    if (keysym == XK_w || keysym == XK_Up)
    {
        if (game->map[(game->player->pos_y - game->size_img) / game->size_img][(game->player->pos_x) / game->size_img] != '1' && allow_exit(keysym, game, game->player->pos_y - game->size_img, game->player->pos_x) == 1)
        {
            game->player->pos_y -= game->size_img;
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->lawn->ptr, game->player->pos_x, game->player->pos_y + game->size_img);
            printf("[%d], Moov : %d\n", game->nb_item, ++(game->nb_moov));
        }
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player->up->ptr, game->player->pos_x, game->player->pos_y);
    }
    else if (keysym == XK_a || keysym == XK_Left )
    {
        if (game->map[(game->player->pos_y) / game->size_img][(game->player->pos_x - game->size_img) / game->size_img] != '1' && allow_exit(keysym, game, game->player->pos_y , game->player->pos_x - game->size_img) == 1)
        {
            game->player->pos_x -= game->size_img;
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->lawn->ptr, game->player->pos_x + game->size_img, game->player->pos_y);
            printf("[%d], Moov : %d\n", game->nb_item, ++(game->nb_moov));
        }
         mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player->left->ptr, game->player->pos_x, game->player->pos_y);
    }
    else if (keysym == XK_s || keysym == XK_Down )
    {
        if (game->map[(game->player->pos_y + game->size_img) / game->size_img][(game->player->pos_x) / game->size_img] != '1' && allow_exit(keysym, game, game->player->pos_y + game->size_img, game->player->pos_x) == 1)
        {
            game->player->pos_y += game->size_img;
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->lawn->ptr, game->player->pos_x, game->player->pos_y - game->size_img);
            printf("[%d], Moov : %d\n", game->nb_item, ++(game->nb_moov));
        }
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player->down->ptr, game->player->pos_x, game->player->pos_y);
    }
    else if (keysym == XK_d || keysym == XK_Right )
    {
        if (game->map[(game->player->pos_y) / game->size_img][(game->player->pos_x + game->size_img) / game->size_img] != '1' && allow_exit(keysym, game, game->player->pos_y, game->player->pos_x + game->size_img) == 1)
        {
            game->player->pos_x += game->size_img;
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->lawn->ptr, game->player->pos_x - game->size_img, game->player->pos_y);
            printf("[%d], Moov : %d\n", game->nb_item, ++(game->nb_moov));
        }
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player->right->ptr, game->player->pos_x, game->player->pos_y);
    }
}