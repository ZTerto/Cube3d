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
	game->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Terto3D", true);
	if (!game->mlx)
	{
		fprintf(stderr, "Error: mlx_init failed\n");
		exit(EXIT_FAILURE);
	}
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
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

void init_fps(t_fps **fps) {
    struct timeval tv;

    *fps = malloc(sizeof(t_fps));
    if (!*fps)
        return;

    (*fps)->current_count = 0;
    (*fps)->former_count = 0;
    memset(&(*fps)->current_time, 0, sizeof((*fps)->current_time));
    memset(&(*fps)->former_time, 0, sizeof((*fps)->former_time));

    gettimeofday(&tv, NULL);
    (*fps)->former_time.seconds = (uint64_t)tv.tv_sec;
    (*fps)->former_time.nanoseconds = (uint64_t)tv.tv_usec * 1000;
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
	while (y < WIN_HEIGHT)
	{
		if (y < WIN_HEIGHT / 2)
			color = game->map.color_up;
		else
			color = game->map.color_floor;

		int x = -1;
		while (++x < WIN_WIDTH)
			mlx_put_pixel(game->img, x, y, color);
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
	//print_map(&game->map);
	map_validate(&game->map);
	init_player(game);
	init_fps(&game->fps);
	update_fps(game->fps);
	init_mlx(game);
	rc_setup(game);
}

