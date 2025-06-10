/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar <ajodar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:40:13 by ajodar            #+#    #+#             */
/*   Updated: 2025/06/08 18:27:22 by ajodar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

//20250608 
// cargamos las texturas en mlx
// main -> init_game_window -> rc_setup -> load_wall_textures
static void	load_wall_textures(t_game *game)
{
	game->tex_no = mlx_load_png(game->map.texture_no);
	game->tex_so = mlx_load_png(game->map.texture_so);
	game->tex_we = mlx_load_png(game->map.texture_we);
	game->tex_ea = mlx_load_png(game->map.texture_ea);
	if (!game->tex_no || !game->tex_so || !game->tex_we || !game->tex_ea)
	{
		fprintf(stderr, "Error: loading textures\n");
		exit(EXIT_FAILURE);
	}
}

//20250608 
// Inicialización de texturas en mlx, la interfaz y limpia todo para pintar el fondo
// main -> init_game_window -> rc_setup
void	rc_setup(t_game *game)
{
	load_wall_textures(game);
	load_ui_frames(game);
	init_background(game);
}
