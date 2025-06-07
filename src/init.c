/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:17:56 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 11:17:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

//20250527
// Inicia la pantallita de mlx y su ventana
// main -> init_game_window -> init_mlx
static void	init_mlx(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "Cube3D", true);
	if (!game->mlx)
	{
		fprintf(stderr, "Error: mlx_init failed\n");
		exit(EXIT_FAILURE);
	}
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
	{
		mlx_terminate(game->mlx);
		fprintf(stderr, "Error: mlx_new_image failed\n");
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(game->mlx, game->img, 0, 0) == -1)
	{
		mlx_terminate(game->mlx);
		fprintf(stderr, "Error: mlx_image_to_window failed\n");
		exit(EXIT_FAILURE);
	}
}

//20250527
// Busca los colores asignados y pinta el suelo y el cielo
// main -> init_game_window -> init_background
static void	init_background(t_game *game)
{
	uint32_t	color;
	int			y;

	y = 0;
	while (y < HEIGHT)
	{
		int x = 0;
		if (y < HEIGHT / 2)
			color = game->map.color_up;
		else
			color = game->map.color_floor;
		while (x < WIDTH)
		{
			mlx_put_pixel(game->img, x, y, color);
			x++;
		}
		y++;
	}
}

//20250527
// Inicializa MLX, saca la pantalla y pinta fondos
// main -> init_game_window
void	init_game_window(t_game *game, char *map_path)
{
	char	full_path[256];

	if (map_setup(&game->map, map_path, full_path, sizeof(full_path)) != 0)
		exit(EXIT_FAILURE);
	print_map(&game->map); // Debugeo de la estructura map (Borrar al final)
	if (map_validate(&game->map) != 0)
		exit(EXIT_FAILURE);
	init_mlx(game);
	init_background(game);
}

