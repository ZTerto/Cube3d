/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar <ajodar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:17:55 by ajodar            #+#    #+#             */
/*   Updated: 2025/06/09 16:33:41 by ajodar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

//20250608
// Borra la ui actual y pinta la nueva que toca
// main -> mlx_loop_hook -> ui_update -> ui_render_frame
static void	ui_render_frame(t_game *game)
{
	int	x;
	int	y;

	mlx_delete_image(game->mlx, game->ui.img);
	game->ui.img = mlx_texture_to_image(game->mlx,
		game->ui.frames[game->ui.current_frame]);
	if (!game->ui.img)
	{
		fprintf(stderr, "Error: can't animate interface\n");
		exit(EXIT_FAILURE);
	}
	x = (WIDTH - game->ui.img->width) / 2;
	y = HEIGHT - game->ui.img->height;
	if (mlx_image_to_window(game->mlx, game->ui.img, x, y) == -1)
	{
		fprintf(stderr, "Error: can't animate interface\n");
		exit(EXIT_FAILURE);
	}
}

//20250608
// Actualiza frame a frame la animación con breve delay cuando se activa
// main -> mlx_loop_hook -> ui_update
void	ui_update(void *param)
{
	t_game *game = (t_game *)param;
	static int delay = 0;

	if (!game->ui.is_animating)
		return;
	delay++;
	if (delay < 10)
		return;
	delay = 0;
	game->ui.current_frame++;
	if (game->ui.current_frame >= game->ui.frame_count)
	{
		game->ui.is_animating = false;
		game->ui.current_frame = 0;
	}
	ui_render_frame(game);
}

//20250608
// Permite comenzar la secuencia de la animación para la ui al moverse
// main -> mlx_key_hook -> handle_key -> handle_movement -> start_ui_anim
// main -> mlx_key_hook -> handle_key -> handle_rotation -> start_ui_anim
void	start_ui_anim(t_game *game)
{
	if (!game->ui.is_animating)
	{
		game->ui.is_animating = true;
		game->ui.current_frame = 0;
	}
}
