/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:35:41 by marvin            #+#    #+#             */
/*   Updated: 2025/05/28 10:35:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

//20250603
// Limpia la copia que usamos para la validación del mapa
// main -> init_game_window -> map_validate -> validate_walls -> free_map_copy
void	free_map_copy(char **map_copy)
{
	int	i;

	i = 0;
	if (!map_copy)
		return;
	while (map_copy[i])
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

//20250528
// Libera la estructura map
// main -> mlx_key_hook -> handle_key -> cleanup_game -> free_map
static void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->complete_map)
	{
		while (map->complete_map[i])
		{
			free(map->complete_map[i]);
			i++;
		}
		free(map->complete_map);
	}
	free(map->texture_no);
	free(map->texture_so);
	free(map->texture_we);
	free(map->texture_ea);
}

//20250528
// Limpia la memoria antes de cerrar
// main -> mlx_key_hook -> handle_key -> cleanup_game
void	cleanup_game(t_game *game)
{
	if (game->img)
		mlx_delete_image(game->mlx, game->img);
	mlx_terminate(game->mlx);
	free_map(&game->map);
	if (game->tex_no) mlx_delete_texture(game->tex_no);
	if (game->tex_so) mlx_delete_texture(game->tex_so);
	if (game->tex_we) mlx_delete_texture(game->tex_we);
	if (game->tex_ea) mlx_delete_texture(game->tex_ea);
}
