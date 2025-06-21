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

void key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player.key_up = true;
	else if (keycode == KEY_S)
		game->player.key_down = true;
	else if (keycode == KEY_A)
		game->player.key_left = true;
	else if (keycode == KEY_D)
		game->player.key_right = true;
	else if (keycode == KEY_LEFT)
		game->player.key_left_rotate = true;
	else if (keycode == KEY_RIGHT)
		game->player.key_right_rotate = true;
}

void key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player.key_up = false;
	else if (keycode == KEY_S)
		game->player.key_down = false;
	else if (keycode == KEY_A)
		game->player.key_left = false;
	else if (keycode == KEY_D)
		game->player.key_right = false;
	else if (keycode == KEY_LEFT)
		game->player.key_left_rotate = false;
	else if (keycode == KEY_RIGHT)
		game->player.key_right_rotate = false;
}

void handle_key_press(mlx_key_data_t keydata, void *param)
{
	t_game *game = (t_game *)param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		cleanup_game(game);
		exit(EXIT_SUCCESS);
	}
	if (keydata.action == MLX_PRESS)
		key_press(keydata.key, game);
    render(param);
}

void handle_key_release(mlx_key_data_t keydata, void *param)
{
	t_game *game = (t_game *)param;

	if (keydata.action == MLX_RELEASE)
		key_release(keydata.key, game);
}
