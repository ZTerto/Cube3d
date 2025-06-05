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

//20250604
// main -> init_game_window -> map_parse -> pad_map_lines -> sanitize_line
char	*sanitize_line(const char *src, int width)
{
	int 	i;
	char	c;
	char	*dst;

	dst = malloc(width + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i] && i < width)
	{
		c = src[i];
		if (c == '0' || c == '1' ||
			c == 'N' || c == 'S' ||
			c == 'E' || c == 'W' ||
			c == ' ')
			dst[i] = c;
		else
			dst[i] = ' ';
		i++;
	}
	while (i < width)
		dst[i++] = ' ';
	dst[i] = '\0';
	return (dst);
}

//20250604
// Completa con espacios el array del mapa
// main -> init_game_window -> map_parse -> pad_map_lines
static void	pad_map_lines(char **map_lines, int total_lines, int width)
{
	char	*clean;
	int		i;

	i = 0;
	while (i < total_lines)
	{
		clean = sanitize_line(map_lines[i], width);
		if (!clean)
			return ;
		free(map_lines[i]);
		map_lines[i] = clean;
		i++;
	}
}

//20250604
// Ignora las líneas que no tengan información útil
// main -> init_game_window -> map_parse -> extract_textures_colors_maps -> is_line_empty
int	is_valid_map_line(const char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == '\0' || *line == '\n')
		return (0);
	if (*line == '1' || *line == '0' || \
		*line == 'N' || *line == 'S' || \
		*line == 'E' || *line == 'W')
		return (1);
	return (0);
}

//20250604
// Completa la estructura map con texturas, colores y el array
// main -> init_game_window -> map_parse -> extract_textures_colors_maps
int	extract_textures_colors_maps(t_map *map, char **tmp_map, int *width, int *map_lines, int fd)
{
	char	*line;
	size_t	len;

	len = 0;
	while ((line = get_next_line(fd)))
	{
		if (!parse_texture_colors(map, line))
		{
			if (is_valid_map_line(line))
			{
				len = ft_strlen(line);
				if (len > 0 && line[len - 1] == '\n')
					line[len - 1] = '\0';
				if ((int)len > *width)
					*width = len;
				tmp_map[*map_lines] = line;
				(*map_lines)++;
			}
			else
				free(line); // línea sin nada
		}
		else
			free(line); // ya parseada como textura o color
	}
	return (0);
}

//20250604
// Lee el archivo .cub y guarda lo necesario en la estructura map
// main -> init_game_window -> map_parse
int	map_parse(t_map *map, char *map_path)
{
	int		fd;
	char	**tmp_map;
	int		map_lines;
	int		width;

	map_lines = 0;
	width = 0;
	init_map(map);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (perror("open"), -1);
	tmp_map = malloc(sizeof(char *) * 1024);
	if (!tmp_map)
		return (close(fd), -1);
	extract_textures_colors_maps(map, tmp_map, &width, &map_lines, fd);
	pad_map_lines(tmp_map, map_lines, width);
	tmp_map[map_lines] = NULL;
	map->complete_map = tmp_map;
	map->height = map_lines;
	map->width = width;
	close(fd);
	return (0);
}
