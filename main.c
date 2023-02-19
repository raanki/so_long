#include "so_long.h"


int main(int argc, char **argv)
{
    t_map game;

    game_ini(&game);
    game.size_img = 40;
    game.mlx_ptr = mlx_init();

    if (check_all(&game) == 0)
      return (0);
   parsing_game(&game);
   //printf("chemin possible ? %d \n", bfs( 3, 1, 3, 6, game.map, game.nb_item));
    mlx_key_hook(game.win_ptr, &handle_keypress, &game);
  mlx_hook(game.win_ptr, 17, 1L<<17, &close_window, &game);
  mlx_loop(game.mlx_ptr);
}