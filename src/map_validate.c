/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:22:05 by marvin            #+#    #+#             */
/*   Updated: 2025/06/03 09:22:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

//20250603
// Confirma la posición inicial del jugador en el mapa para hacer luego flood fill desde ahí
// main -> init_game_window -> map_validate -> validate_player_start
int	validate_player_start(char **map, int *x, int *y)
{
	int i;
	int j;
	int found;

	i = 0;
	found = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'E' || map[i][j] == 'W')
			{
				*x = j;
				*y = i;
				found++;
			}
			j++;
		}
		i++;
	}
	if (found != 1)
		return (fprintf(stderr, "Error: player not correct\n"), 1);
	return (0);
}

//20250603
// Valida que el mapa sea jugable
// main -> init_game_window -> map_validate
int	map_validate(t_map *map)
{
	int	start_x;
	int	start_y;

	if (validate_player_start(map->complete_map, &start_x, &start_y) != 0)
		return (1);
	if (validate_walls(map->complete_map, start_x, start_y) != 0)
		return (1);
	return (0);
}
