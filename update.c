// #include "so_long.h"

// int update_animation(t_img_data *piece)
// {
//     static void *images[10] = {0}; // initialiser à NULL la première fois pour éviter des problèmes de pointeur indéfini

//     if (images[0] == NULL) { // charger les images la première fois seulement
//         int a = 64;
//         int *height = &a;
//         int *width = &a;
//         images[0] = mlx_xpm_file_to_image(piece->mlx_ptr, "sprites/Gold_1.xpm", height, width);
//         images[1] = mlx_xpm_file_to_image(piece->mlx_ptr, "sprites/Gold_2.xpm", height, width);
//         images[2] = mlx_xpm_file_to_image(piece->mlx_ptr, "sprites/Gold_3.xpm", height, width);
//         images[3] = mlx_xpm_file_to_image(piece->mlx_ptr, "sprites/Gold_4.xpm", height, width); 
//         images[4] = mlx_xpm_file_to_image(piece->mlx_ptr, "sprites/Gold_5.xpm", height, width);
//         images[5] = mlx_xpm_file_to_image(piece->mlx_ptr, "sprites/Gold_6.xpm", height, width);
//         images[6] = mlx_xpm_file_to_image(piece->mlx_ptr, "sprites/Gold_7.xpm", height, width);
//         images[7] = mlx_xpm_file_to_image(piece->mlx_ptr, "sprites/Gold_8.xpm", height, width);
//         images[8] = mlx_xpm_file_to_image(piece->mlx_ptr, "sprites/Gold_9.xpm", height, width);
//         images[9] = mlx_xpm_file_to_image(piece->mlx_ptr, "sprites/Gold_10.xpm", height, width);
//     }
//     if (images[*(piece->frame)] != NULL)
//     {
//         piece->piece_ptr = images[*(piece->frame)]; // utiliser l'image chargée précédemment
//         mlx_put_image_to_window(piece->mlx_ptr, piece->win_ptr, piece->piece_ptr, 64, 64);
//         *(piece->frame) = (*(piece->frame) + 1 ) % 10;
//     }
//    return (0);
// }