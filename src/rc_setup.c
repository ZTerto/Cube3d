/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar <ajodar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:40:13 by ajodar            #+#    #+#             */
/*   Updated: 2025/06/08 13:18:02 by ajodar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

static void	load_wall_textures(t_game *game)
{
	game->tex_no = mlx_load_png(game->map.texture_no);
	game->tex_so = mlx_load_png(game->map.texture_so);
	game->tex_we = mlx_load_png(game->map.texture_we);
	game->tex_ea = mlx_load_png(game->map.texture_ea);

	if (!game->tex_no || !game->tex_so || !game->tex_we || !game->tex_ea)
	{
		fprintf(stderr, "Error: No se pudieron cargar todas las texturas\n");
		exit(EXIT_FAILURE);
	}
}

//20250608 
// Inicialización de texturas o z-buffer en el futuro
void	rc_setup(t_game *game)
{
	load_wall_textures(game);
}
