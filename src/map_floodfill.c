/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_floodfill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:47:16 by marvin            #+#    #+#             */
/*   Updated: 2025/06/03 09:47:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

//20250603
// main -> init_game_window -> map_validate -> validate_walls -> duplicate_map
static char	**duplicate_map(char **map)
{
	int		i;
	char	**copy;

	i = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

//20250603
// main -> init_game_window -> map_validate -> validate_walls -> flood_check
static void flood_check(char **map, int x, int y, int *count, int *valid)
{
	if (*count >= 400 || *valid != 0)
		return;
	(*count)++;

	if (map[y][x] == '\0' || map[y][x] == ' ')
	{
		*valid = 1;
		return;
	}
	if (map[y][x] == '1' || map[y][x] == 'V')
		return;
	if (map[y][x] != '0' && map[y][x] != 'N' && map[y][x] != 'S' && \
		map[y][x] != 'E' && map[y][x] != 'W')
	{
		*valid = 1;
		return;
	}
	map[y][x] = 'V';
	flood_check(map, x + 1, y, count, valid);
	flood_check(map, x - 1, y, count, valid);
	flood_check(map, x, y + 1, count, valid);
	flood_check(map, x, y - 1, count, valid);
}

//20250603
// Valida que los muros cierren lanzando un floodfill desde dentro
// main -> init_game_window -> map_validate -> validate_walls
int	validate_walls(char **map, int start_x, int start_y)
{
	char	**map_copy;
	int		valid;
	int		count;

	count = 0;
	valid = 0;
	map_copy = duplicate_map(map);
	if (!map_copy)
	{
		fprintf(stderr, "Error: Failed to duplicate the map for wall validation.\n");
		return (1);
	}
	flood_check(map_copy, start_x, start_y, &count, &valid);
	free_map_copy(map_copy);
	if (valid != 0)
	{
		fprintf(stderr, "Error: Map is not closed by walls.\n");
		return (1);
	}
	return (0);
}

