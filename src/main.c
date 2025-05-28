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

//20250528
// Gestiona la pulsación de teclas, ahora mismo saca del juego con escape
// main -> mlx_key_hook -> handle_key
void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_game *game = (t_game *)param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		cleanup_game(game);
		exit(EXIT_SUCCESS);
	}
}

//20250527
int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	init_game_window(&game, argv[1]);
	mlx_key_hook(game.mlx, handle_key, &game);
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
}*/