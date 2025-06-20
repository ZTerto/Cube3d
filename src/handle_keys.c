/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar <ajodar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:02:17 by ajodar            #+#    #+#             */
/*   Updated: 2025/06/09 16:44:24 by ajodar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

//20250608
// Cierra el juego al presionar scape y libera la memoria
// main -> mlx_key_hook -> handle_key -> handle_scape
static void	handle_escape(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		cleanup_game(game);
		exit(EXIT_SUCCESS);
	}
}

//20250608
// El personaje actualiza su localización 
// main -> mlx_key_hook -> handle_key -> handle_movement
static void	handle_movement(t_game *game, mlx_key_data_t keydata)
{
	double next_x;
	double next_y;

	if (keydata.key == MLX_KEY_W)
	{
		next_x = game->player.x + game->player.dir_x * MOVE_SPEED;
		next_y = game->player.y + game->player.dir_y * MOVE_SPEED;
	}
	else 	if (keydata.key == MLX_KEY_S)
	{
		next_x = game->player.x - game->player.dir_x * MOVE_SPEED;
		next_y = game->player.y - game->player.dir_y * MOVE_SPEED;
	}
	else
		return ;
	if (game->map.complete_map[(int)next_y][(int)game->player.x] != '1')
		game->player.y = next_y;
	if (game->map.complete_map[(int)game->player.y][(int)next_x] != '1')
		game->player.x = next_x;
	start_ui_anim(game);
}

//20250608
// El personaje rota sobre su eje actualizando el punto de vista
// main -> mlx_key_hook -> handle_key -> handle_movement


static void	handle_rotation(t_game *game, mlx_key_data_t keydata)
{
	double rot_speed;
	double cos_r;
	double sin_r;
	double old_dir_x;
	double old_plane_x;

	if (keydata.key == MLX_KEY_D)
		rot_speed = ROT_SPEED;
	else if (keydata.key == MLX_KEY_A)
		rot_speed = -ROT_SPEED;
	else
		return;

	cos_r = cos(rot_speed);
	sin_r = sin(rot_speed);

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos_r - game->player.dir_y * sin_r;
	game->player.dir_y = old_dir_x * sin_r + game->player.dir_y * cos_r;

	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos_r - game->player.plane_y * sin_r;
	game->player.plane_y = old_plane_x * sin_r + game->player.plane_y * cos_r;

	start_ui_anim(game);
}




//20250608
// Gestiona la salida del programa con scape, el movimiento, rotación y animación de la interfaz
// main -> mlx_key_hook -> handle_key
void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_game *game = (t_game *)param;

	handle_escape(keydata, game);
	if (keydata.action != MLX_PRESS && keydata.action != MLX_REPEAT)
		return;
	handle_movement(game, keydata);
	handle_rotation(game, keydata);
	//handle_mouse_rotation(void *param);
}
