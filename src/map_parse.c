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
// Lee el archivo .cub y guarda lo necesario en la estructura map
// main -> init_game_window -> map_parse
int	map_parse(t_map *map, char *map_path)
{
	int		fd;
	char	*line;
	char	**tmp_map;
	int		map_lines = 0;
	int		i = 0;
	int		width = 0;

	init_map(map);
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
		int len = ft_strlen(line);
		if (len > width)
			width = len;
		tmp_map[map_lines++] = line;
	}

	for (i = 0; i < map_lines; i++)
	{
		int len = ft_strlen(tmp_map[i]);
		if (len < width)
		{
			char *padded = malloc(width + 1);
			ft_strlcpy(padded, tmp_map[i], len + 1);
			while (len < width)
				padded[len++] = ' ';
			padded[len] = '\0';
			free(tmp_map[i]);
			tmp_map[i] = padded;
		}
	}
	tmp_map[map_lines] = NULL;

	map->complete_map = tmp_map;
	map->height = map_lines;
	map->width = width;
	close(fd);
	return (0);
}


