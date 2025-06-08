/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar <ajodar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:02:17 by ajodar            #+#    #+#             */
/*   Updated: 2025/06/08 14:04:24 by ajodar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"
#include "../include/raycasting.h"

//20250528
// Gestiona la pulsación de teclas, ahora mismo saca del juego con escape
// main -> mlx_key_hook -> handle_key
void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_game *game = (t_game *)param;
	double move_speed = 0.05;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		cleanup_game(game);
		exit(EXIT_SUCCESS);
	}
	if (keydata.action != MLX_PRESS && keydata.action != MLX_REPEAT)
		return;

	if (keydata.key == MLX_KEY_W)
	{
		double next_x = game->player.x + game->player.dir_x * move_speed;
		double next_y = game->player.y + game->player.dir_y * move_speed;

		if (game->map.complete_map[(int)next_y][(int)game->player.x] != '1')
			game->player.y = next_y;
		if (game->map.complete_map[(int)game->player.y][(int)next_x] != '1')
			game->player.x = next_x;
	}
	if (keydata.key == MLX_KEY_S)
	{
		double next_x = game->player.x - game->player.dir_x * move_speed;
		double next_y = game->player.y - game->player.dir_y * move_speed;

		if (game->map.complete_map[(int)next_y][(int)game->player.x] != '1')
			game->player.y = next_y;
		if (game->map.complete_map[(int)game->player.y][(int)next_x] != '1')
			game->player.x = next_x;
	}
		if (keydata.key == MLX_KEY_D)
	{
		double rot_speed = 0.05;
		double old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(rot_speed) - game->player.dir_y * sin(rot_speed);
		game->player.dir_y = old_dir_x * sin(rot_speed) + game->player.dir_y * cos(rot_speed);

		double old_plane_x = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(rot_speed) - game->player.plane_y * sin(rot_speed);
		game->player.plane_y = old_plane_x * sin(rot_speed) + game->player.plane_y * cos(rot_speed);
	}
	if (keydata.key == MLX_KEY_A)
	{
		double rot_speed = -0.05;
		double old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(rot_speed) - game->player.dir_y * sin(rot_speed);
		game->player.dir_y = old_dir_x * sin(rot_speed) + game->player.dir_y * cos(rot_speed);

		double old_plane_x = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(rot_speed) - game->player.plane_y * sin(rot_speed);
		game->player.plane_y = old_plane_x * sin(rot_speed) + game->player.plane_y * cos(rot_speed);
	}
}
