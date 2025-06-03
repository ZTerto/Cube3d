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
// main -> init_game_window -> map_validate -> validate_walls -> flood_check -> is_invalid_cell
static bool	is_invalid_cell(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != ' ')
	{
		fprintf(stderr, "Error: Invalid character '%c' found in the map\n", c);
		return (true);
	}
	return (false);
}


//20250603
// main -> init_game_window -> map_validate -> validate_walls -> flood_check
static bool flood_check(char **map, int x, int y, int height, int *count)
{
	if (*count > 400)
		return (true);
	(*count)++;
	if (is_invalid_cell(map[y][x]))
		return (true);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (false);
	map[y][x] = 'V';
	return (flood_check(map, x + 1, y, height, count) ||
			flood_check(map, x - 1, y, height, count) ||
			flood_check(map, x, y + 1, height, count) ||
			flood_check(map, x, y - 1, height, count));
}

//20250603
// Valida que los muros cierren lanzando un floodfill desde dentro
// main -> init_game_window -> map_validate -> validate_walls
bool	validate_walls(char **map, int start_x, int start_y, int height)
{
	char	**map_copy;
	bool	leak;
	int		count;

	count = 0;
	map_copy = duplicate_map(map);
	if (!map_copy)
	{
		fprintf(stderr, "Error: Failed to duplicate the map for wall validation.\n");
		return (false);
	}
	leak = flood_check(map_copy, start_x, start_y, height, &count);
	free_map_copy(map_copy);
	if (leak)
	{
		fprintf(stderr, "Error: Map is not closed by walls or contains open space near boundaries.\n");
		return (false);
	}
	return (true);
}


