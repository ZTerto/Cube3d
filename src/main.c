/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:17:52 by marvin            #+#    #+#             */
/*   Updated: 2025/06/20 08:18:02 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

//20250527
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	init_game_window(&game, argv[1]);
	mlx_key_hook(game.mlx, handle_key_press, &game);
	mlx_key_hook(game.mlx, handle_key_release, &game);
	// mlx_set_cursor_mode(game.mlx, MLX_MOUSE_DISABLED);
	//mlx_loop_hook(game.mlx, handle_mouse, &game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop_hook(game.mlx, ui_update, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
