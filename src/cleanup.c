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
}
