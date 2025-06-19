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


# include "defines.h"
# include "structs.h"



// Init
void		init_game_window(t_game *game, char *map_path);
void		init_map(t_map *map);
int			map_setup(t_map *map, char *map_name);
void		init_player(t_game *game);
void		init_background(t_game *game);

// Handle_keys
void		handle_key(mlx_key_data_t keydata, void *param);
void		handle_mouse_rotation(void *param);

// UI animation
void		load_ui_frames(t_game *game);
void		ui_update(void *param);
void		start_ui_anim(t_game *game);

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

// setup
void	rc_setup(t_game *game);

// render
void	render(void *param);
void	perform_dda(t_ray *ray, t_game *game);
void	rc_render_frame(t_game *game);
void	cast_ray(t_game *game, int x);
void	setup_ray(t_ray *ray, t_game *game, int x);

// draw
void	draw_column(t_game *game, int x, t_ray *ray);

//counter.c
void print_counter(void *param);
void update_fps(t_fps *fps);



#endif
