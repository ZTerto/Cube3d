/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:41:53 by marvin            #+#    #+#             */
/*   Updated: 2025/06/04 10:41:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

//20250607
// Limpia la textura de espacios, tabulaciones y salto ants de guardarla
// main -> init_game_window -> map_parse -> parse_texture_colors -> parse_texture -> clean_texture
static int	clean_texture(char **texture_field, const char *prefix, char *line)
{
	char *clean;

	if (*texture_field != NULL)
		return (0);
	clean = ft_strtrim(line + ft_strlen(prefix), " \t\n\r");
	if (!clean)
		return (0);
	*texture_field = clean;
	return (1);
}

//20250607
// main -> init_game_window -> map_parse -> parse_texture_colors -> parse_texture
static int	parse_texture(t_map *map, char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;

	if (!ft_strncmp(line, "NO ", 3))
		return clean_texture(&map->texture_no, "NO ", line);
	if (!ft_strncmp(line, "SO ", 3))
		return clean_texture(&map->texture_so, "SO ", line);
	if (!ft_strncmp(line, "WE ", 3))
		return clean_texture(&map->texture_we, "WE ", line);
	if (!ft_strncmp(line, "EA ", 3))
		return clean_texture(&map->texture_ea, "EA ", line);

	return (0);
}

//20250527
// Guarda los colores con un formato que pueda leer mlx
// main -> init_game_window -> map_parse -> parse_texture_colors -> parse_rgb
uint32_t	parse_rgb(const char *str)
{
	char	**split;
	int		r, g, b, i;
	split = ft_split(str, ',');
	if (!split || !split[0] || !split[1] || !split[2])
		return (0);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (r << 24) | (g << 16) | (b << 8) | 0xFF;
}

//20250605
// main -> init_game_window -> map_parse -> parse_texture_colors -> parse_color
static int	parse_color(t_map *map, char *line)
{
	if (!ft_strncmp(line, "F ", 2) && map->color_floor == 0xFFFFFFFF)
		map->color_floor = parse_rgb(line + 2);
	else if (!ft_strncmp(line, "C ", 2) && map->color_up == 0xFFFFFFFF)
		map->color_up = parse_rgb(line + 2);
	else
		return (0);
	return (1);
}

//20250527
// Busca las texturas y colores para guardarls en la estructura
// main -> init_game_window -> map_parse -> parse_texture_colors
int	parse_texture_colors(t_map *map, char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (parse_texture(map, line))
		return (1);
	if (parse_color(map, line))
		return (1);
	return (0);
}
