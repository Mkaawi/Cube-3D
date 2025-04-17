/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:44:42 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/17 22:15:08 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

int	textures_init(t_m *data, t_data *pars_data)
{
	data->ceiling_color = pars_data->cieling_color;
	data->floor_color = pars_data->floor_color;
	data->texture.north = mlx_load_png(pars_data->north_text);
	data->texture.south = mlx_load_png(pars_data->south_text);
	data->texture.east = mlx_load_png(pars_data->east_text);
	data->texture.west = mlx_load_png(pars_data->west_text);
	if (!data->texture.north || !data->texture.east || !data->texture.south
		|| !data->texture.west)
		return (1);
	return (0);
}

void	delete_textures(t_m data)
{
	if (data.texture.north)
		mlx_delete_texture(data.texture.north);
	if (data.texture.south)
		mlx_delete_texture(data.texture.south);
	if (data.texture.east)
		mlx_delete_texture(data.texture.east);
	if (data.texture.west)
		mlx_delete_texture(data.texture.west);
}

int	raycasting_entry(t_data *pars_data)
{
	t_m	data;

	data.map = pars_data->map;
	data.mlx = mlx_init(WIDTH, HEIGHT, "cube3d", true);
	if (!data.mlx)
		return (1);
	data.image = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.image)
		return (1);
	if (mlx_image_to_window(data.mlx, data.image, 0, 0) == -1)
		return (1);
	if (textures_init(&data, pars_data))
	{
		mlx_terminate(data.mlx);
		delete_textures(data);
		return (1);
	}
	player_init(&data);
	shot_rays(&data);
	mlx_loop_hook(data.mlx, ft_hook, &data);
	mlx_loop(data.mlx);
	delete_textures(data);
	mlx_terminate(data.mlx);
	return (1);
}
