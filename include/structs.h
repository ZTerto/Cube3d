/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar <ajodar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 13:00:11 by ajodar            #+#    #+#             */
/*   Updated: 2025/06/09 19:12:18 by ajodar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
# include <sys/time.h>
# include <string.h>
#include <stdint.h>

typedef struct s_time_interval {
    uint64_t seconds;
    uint64_t nanoseconds;
} t_time_interval;

typedef struct s_fps {
    int current_count;
    t_time_interval current_time;
    int former_count;
    t_time_interval former_time;
} t_fps;


typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	int		map_x;
	int		map_y;

	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;

	int		step_x;
	int		step_y;

	int		hit;
	int		side;

	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;


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

	bool key_up;
    bool key_down;
    bool key_right;
    bool key_left;
	bool key_left_rotate;
    bool key_right_rotate;
}	t_player;

typedef struct s_ui_anim {
	mlx_texture_t	*frames[4];
	mlx_image_t		*img;
	int				frame_count;
	int				current_frame;
	bool			is_animating;
}	t_ui_anim;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_map			map;
	t_player		player;
	t_fps			*fps;
	mlx_texture_t	*tex_no;
	mlx_texture_t	*tex_so;
	mlx_texture_t	*tex_we;
	mlx_texture_t	*tex_ea;
	t_ui_anim		ui;
}	t_game;



#endif
