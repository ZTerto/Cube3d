/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:17:52 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 11:17:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"
#include "../include/raycasting.h"

//20250527
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	init_game_window(&game, argv[1]);
	mlx_key_hook(game.mlx, handle_key, &game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop_hook(game.mlx, ui_update, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}

/*
//20250528
// main de prueba para ver leaks generados por la librería de Codam
int main(void)
{
	mlx_t *mlx = mlx_init(400, 400, "test", true);
	mlx_terminate(mlx);
	return 0;
}
*/