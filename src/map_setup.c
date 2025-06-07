/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar <ajodar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 11:03:45 by ajodar            #+#    #+#             */
/*   Updated: 2025/06/07 11:17:24 by ajodar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

//20250604
// Limpia lo que tenga la estructura de mapa antes de usarla
// main -> init_game_window -> map_setup -> init_map
void	init_map(t_map *map)
{
	map->texture_no = NULL;
	map->texture_so = NULL;
	map->texture_we = NULL;
	map->texture_ea = NULL;
	map->color_floor = 0xFFFFFFFF;
	map->color_up = 0xFFFFFFFF;
	map->complete_map = NULL;
	map->width = 0;
	map->height = 0;
}

//20250607
// Valida la ruta del mapa
// main -> init_game_window -> map_setup -> validate_map_path
static int	validate_map_path(const char *path)
{
	int		len;
	int		fd;

	len = ft_strlen(path);
	if (len < 5 || ft_strncmp(path + len - 4, ".cub", 4) != 0)
	{
		printf("Error: map dont have extension .cub\n");
		return (1);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error: open the map");
		return (1);
	}
	close(fd);
	return (0);
}

//20250527
// Crea full_path con la ruta hasta maps/ y el nombre del mapa como argumento
// main -> init_game_window -> map_setup -> build_map_path
static void	build_map_path(char *dest, const char *filename, size_t size)
{
	ft_strlcpy(dest, "maps/", size);
	ft_strlcat(dest, filename, size);
}

//20250607
// Crea la ruta completa al mapa, valida y parsea todo a la estructura map
// main -> init_game_window -> map_setup
int	map_setup(t_map *map, const char *map_name, char *full_path, size_t max_len)
{
	build_map_path(full_path, map_name, max_len);
	if (validate_map_path(full_path) != 0)
		return (1);
	if (map_parse(map, full_path) != 0)
		return (1);
	return (0);
}
