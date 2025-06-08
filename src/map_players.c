/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar <ajodar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 11:08:25 by ajodar            #+#    #+#             */
/*   Updated: 2025/06/08 12:12:25 by ajodar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

//20250608
static void	set_player_direction_vertical(t_player *p, char dir)
{
	if (dir == 'N')
	{
		p->dir_x = 0;
		p->dir_y = -1;
		p->plane_x = 0.66;
		p->plane_y = 0;
	}
	else if (dir == 'S')
	{
		p->dir_x = 0;
		p->dir_y = 1;
		p->plane_x = -0.66;
		p->plane_y = 0;
	}
}

//20250608
static void	set_player_direction_horizontal(t_player *p, char dir)
{
	if (dir == 'E')
	{
		p->dir_x = 1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		p->dir_x = -1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = -0.66;
	}
}

//20250608
static void	set_player_direction(t_player *p, char dir)
{
	if (dir == 'N' || dir == 'S')
		set_player_direction_vertical(p, dir);
	else if (dir == 'E' || dir == 'W')
		set_player_direction_horizontal(p, dir);
}

//20250608
static void	set_player_position(t_game *game, int x, int y, char dir)
{
	game->player.x = x + 0.5;
	game->player.y = y + 0.5;
	set_player_direction(&game->player, dir);
	game->map.complete_map[y][x] = '0';
}

//20250608
// Gestiona los datos de posición y vistas del jugador en el mapa
// main -> init_game_window -> init_player
void	init_player(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (game->map.complete_map[y])
	{
		x = 0;
		while (game->map.complete_map[y][x])
		{
			c = game->map.complete_map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				set_player_position(game, x, y, c);
				return ;
			}
			x++;
		}
		y++;
	}
}
