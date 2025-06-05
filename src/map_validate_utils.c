/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar <ajodar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:26:58 by ajodar            #+#    #+#             */
/*   Updated: 2025/06/05 11:32:17 by ajodar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

//20250605
// Abre la ruta de la textura, si no abre nada devuelve error
// main -> init_game_window -> map_validate
static int	validate_texture_path(char *path)
{
	mlx_texture_t *tex;

	tex = mlx_load_png(path);
	if (!tex)
	{
		printf("Error: can't load texture: %s\n", path);
		return (0);
	}
	mlx_delete_texture(tex);
	return (1);
}

//20250605
// Confirma que el color sea correcto en el formato rgb
// main -> init_game_window -> map_validate
static int	validate_rgb_format(uint32_t color, const char *label)
{
	int r = (color >> 24) & 0xFF;
	int g = (color >> 16) & 0xFF;
	int b = (color >> 8) & 0xFF;
	int a = color & 0xFF;

	if (a != 0xFF)
	{
		printf("Error: %s alpha no válido (esperado 0xFF): %02X\n", label, a);
		return (0);
	}
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		printf("Error: %s color fuera de rango: (%d,%d,%d)\n", label, r, g, b);
		return (0);
	}
	return (1);
}

//20250605
// Valida las rutas a las texturas y si los colores son válidos
// main -> init_game_window -> map_validate
int	validate_colors_and_textures(t_map *map)
{
	if (!map->texture_no || !map->texture_so || \
		!map->texture_we || !map->texture_ea)
	{
		printf("Error: not enough textures\n");
		return (1);
	}
	if (!validate_texture_path(map->texture_no) || \
		!validate_texture_path(map->texture_so) || \
		!validate_texture_path(map->texture_we) || \
		!validate_texture_path(map->texture_ea))
	{
		printf("Error: reading the texture\n");
		return (1);
	}
	if (!validate_rgb_format(map->color_floor, "floor") || \
	!validate_rgb_format(map->color_up, "ceiling"))
		return (1);
	return (0);
}
