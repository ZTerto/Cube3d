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
#include "../include/raycasting.h"

//20250527
// Inicia la pantallita de mlx y su ventana
// main -> init_game_window -> init_mlx
static void	init_mlx(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "Terto3D", true);
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
// main -> init_game_window -> rc_setup -> init_background
// main -> render -> rc_render_frame -> init_background (Cada vez que renderiza)
void	init_background(t_game *game)
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

//202500608
// (PARSE) map_setup: Realiza el parse a las estructuras del mapa
// (PARSE) print_map: Imprime en pantalla todo lo parseado del mapa
// (PARSE) map_validate: si algo parseado del mapa no es válido, cierra todo
// (PARSE) init_player: completa los valores de la estructura player
// (MLX) init_mlx: Inicia MLX
// (MLX) init_background: pinta el fondo de los 2 colores parseados antes
// main -> init_game_window
void	init_game_window(t_game *game, char *map_path)
{
	map_setup(&game->map, map_path);
	print_map(&game->map); // Debug temporal
	map_validate(&game->map);
	init_player(game);
	init_mlx(game);
	rc_setup(game);
}

