/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parseo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:18:30 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 12:18:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

//20250527
// Guarda los colores con un formato que pueda leer mlx
// main -> init_game_window -> map_parse -> parse_texture_colors -> parse_rgb
static uint32_t	parse_rgb(const char *str)
{
	int		r;
	int		g;
	int		b;
	int		i;
	char	**split;

	split = ft_split(str, ',');
	if (!split || !split[0] || !split[1] || !split[2])
		return (0);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (r << 24) | (g << 16) | (b << 8) | 0xFF;
}

//20250527
// Busca las texturas y colores para guardarls en la estructura
// main -> init_game_window -> map_parse -> parse_texture_colors
static void	parse_texture_colors(t_map *map, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		map->texture_no = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "SO ", 3))
		map->texture_so = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "WE ", 3))
		map->texture_we = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "EA ", 3))
		map->texture_ea = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "F ", 2))
		map->color_floor = parse_rgb(line + 2);
	else if (!ft_strncmp(line, "C ", 2))
		map->color_up = parse_rgb(line + 2);
}

//20250527
// Lee el archivo .cub y guarda lo necesario en la estructura map
// main -> init_game_window -> map_parse
int	map_parse(t_map *map, char *map_path)
{
	int		fd;
	char	*line;
	char	**tmp_map;
	int		map_lines;
	int		i;

	map_lines = 0;
	i = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (perror("open"), -1);
	tmp_map = malloc(sizeof(char *) * 1024);
	if (!tmp_map)
		return (close(fd), -1);
	while (i < 7 && (line = get_next_line(fd)))
	{
		parse_texture_colors(map, line);
		free(line);
		i++;
	}
	while ((line = get_next_line(fd)))
	{
		tmp_map[map_lines++] = ft_strdup(line);
		free(line);
	}
	tmp_map[map_lines] = NULL;
	map->complete_map = tmp_map;
	map->height = map_lines;
	map->width = ft_strlen(tmp_map[0]);
	close(fd);
	return (0);
}

