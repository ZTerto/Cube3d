/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:18:18 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 11:18:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "MLX42/MLX42.h"
# include "../src/libft/libft.h"
# include "../src/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

// Cons
# define WIDTH 800
# define HEIGHT 600
# define FOV 60.0

// Structs
typedef struct s_map {
	char		*texture_no;
	char		*texture_so;
	char		*texture_we;
	char		*texture_ea;
	uint32_t	color_floor;
	uint32_t	color_up;
	char		**complete_map;
	int			width;
	int			height;
}	t_map;

typedef struct s_player {
	double x;
	double y;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;
}	t_player;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_map			map;
	t_player		player;

	// Nuevas texturas cargadas
	mlx_texture_t	*tex_no;
	mlx_texture_t	*tex_so;
	mlx_texture_t	*tex_we;
	mlx_texture_t	*tex_ea;
}	t_game;


// Init
void		init_game_window(t_game *game, char *map_path);
void		init_map(t_map *map);
int			map_setup(t_map *map, char *map_name);
void		init_player(t_game *game);
void		init_background(t_game *game);

// Handle_keys
void		handle_key(mlx_key_data_t keydata, void *param);

// Parse
int			map_parse(t_map *map, char *map_path);
uint32_t	parse_rgb(const char *str);
int			parse_texture_colors(t_map *map, char *line);

// Validation
int			map_validate(t_map *map);
int			validate_walls(char **map, int start_x, int start_y);
int			validate_colors_and_textures(t_map *map);

// Cleanup
void		cleanup_game(t_game *game);
void		free_map_copy(char **map_copy);

// Debug (Borrar luego)
void		print_map(t_map *map);
void		print_map_copy(char **map);

#endif
