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

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cube3d.h"

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




#endif
