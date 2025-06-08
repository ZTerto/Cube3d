/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar <ajodar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 11:15:16 by ajodar            #+#    #+#             */
/*   Updated: 2025/06/08 11:31:45 by ajodar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

#include "raycasting.h"
#include <math.h> // para fabs()

#include "raycasting.h"
#include <math.h> // Para fabs

void	setup_ray(t_ray *ray, t_game *game, int x)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;

	ray->ray_dir_x = game->player.dir_x + game->player.plane_x * ray->camera_x;
	ray->ray_dir_y = game->player.dir_y + game->player.plane_y * ray->camera_x;

	ray->map_x = (int)game->player.x;
	ray->map_y = (int)game->player.y;

	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);

	ray->hit = 0;

	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.x) * ray->delta_dist_x;
	}

	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.y) * ray->delta_dist_y;
	}
}

void	cast_ray(t_game *game, int x)
{
	t_ray	ray;

	setup_ray(&ray, game, x);

	// Próximo paso: perform_dda(&ray, game);
	// Luego: draw_column(game, x, &ray);
}

void	rc_render_frame(t_game *game)
{
	int	x = 0;

	while (x < WIDTH)
	{
		cast_ray(game, x);
		x++;
	}
}
