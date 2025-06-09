/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_load_frames.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar <ajodar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 18:05:30 by ajodar            #+#    #+#             */
/*   Updated: 2025/06/09 12:52:37 by ajodar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

//20250608
// Inicializa los valores de animación para luego poder arrancar
static void	init_ui_anim_state(t_game *game)
{
	game->ui.frame_count = 4;
	game->ui.current_frame = 0;
	game->ui.is_animating = false;
}

//20250608
// Carga la imagen con la ruta de la textura y lo guarda como parte de ui
// main -> init_game_window -> rc_setup -> load_ui_frames -> create_ui_image
static void	create_ui_image(t_game *game)
{
	int x;
	int y;

	game->ui.img = mlx_texture_to_image(game->mlx, game->ui.frames[0]);
	if (!game->ui.img)
	{
		fprintf(stderr, "Error: creating interface\n");
		exit(EXIT_FAILURE);
	}
	x = (WIDTH - game->ui.img->width) / 2;
	y = HEIGHT - game->ui.img->height;
	if (mlx_image_to_window(game->mlx, game->ui.img, x, y) == -1)
	{
		fprintf(stderr, "Error: creating interface\n");
		exit(EXIT_FAILURE);
	}
}

//20250608
// Carga la ruta de los png de la interfaz
// main -> init_game_window -> rc_setup -> load_ui_frames -> load_ui_textures
static void	load_ui_textures(t_game *game)
{
	int		i;
	char *paths[4];

	paths[0] = "./textures/interface/frame0.png";
	paths[1] = "./textures/interface/frame1.png";
	paths[2] = "./textures/interface/frame2.png";
	paths[3] = "./textures/interface/frame3.png";
	i = 0;
	while (i < 4)
	{
		game->ui.frames[i] = mlx_load_png(paths[i]);
		if (!game->ui.frames[i])
		{
			fprintf(stderr, "Error: loading frame %d\n", i);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

//20250608
// Carga las texturas de la interfaz, prepara el inicio y pinta las imágenes en pantalla
// main -> init_game_window -> rc_setup -> load_ui_frames
void	load_ui_frames(t_game *game)
{
	load_ui_textures(game);
	create_ui_image(game);
	init_ui_anim_state(game);
}
