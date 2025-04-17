/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:45:17 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/17 18:02:17 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

int	abs(int n)
{
	if (n > 0)
		return (n);
	return (n * (-1));
}

void	shot_rays(t_m *data)
{
	t_ray	ray;
	t_hit	hit;
	float	start_angle;
	float	angle_step;
	double	fov;

	fov = data->player.fov;
	start_angle = normalize_angle(data->player.direction - (fov / 2));
	angle_step = data->player.fov / NUM_RAYS;
	ray.angle = start_angle;
	ray.index = 0;
	while (ray.index < NUM_RAYS)
	{
		ray.angle = normalize_angle(ray.angle);
		hit = cast_ray(data, ray.angle);
		ray.hit_x = hit.x;
		ray.hit_y = hit.y;
		ray.distance = hit.distance * cos(normalize_angle(data->player.direction
					- ray.angle));
		ray.is_ver = hit.is_ver;
		render_walls(data, ray);
		ray.angle += angle_step;
		ray.index++;
	}
}
