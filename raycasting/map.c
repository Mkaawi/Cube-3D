/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:46:25 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/17 18:03:24 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

bool	in_map(char **map, int y, int x)
{
	if (y < 0 || x < 0 || y >= get_height(map) || x >= my_strlen(map[y]))
		return (false);
	return (true);
}

bool	has_wall_at(char **map, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = x / TILE_SIZE;
	map_y = y / TILE_SIZE;
	if (in_map(map, map_y, map_x))
		return (map[map_y][map_x] == '1');
	return (false);
}

void	update(t_m *data)
{
	mlx_delete_image(data->mlx, data->image);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	shot_rays(data);
}
