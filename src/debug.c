/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:38:09 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 12:38:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

//20250527
// Printea el mapa guardado (Indicando también sus dimensiones)
void	print_map(t_map *map)
{
	int y;

	y = 0;
	printf("Mapa (%d x %d):\n", map->width, map->height);
	while (map->complete_map && map->complete_map[y])
	{
		printf("%s", map->complete_map[y]);
		y++;
	}
}
