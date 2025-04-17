/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:32:18 by abdennac          #+#    #+#             */
/*   Updated: 2025/04/17 22:20:30 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

int	is_player(int c)
{
	if (c == 'S' || c == 'E')
		return (1);
	if (c == 'N' || c == 'W')
		return (1);
	return (0);
}

int	info_check(t_data *data)
{
	if (!data->north_text)
		return (1);
	if (!data->south_text)
		return (1);
	if (!data->east_text)
		return (1);
	if (!data->west_text)
		return (1);
	if (!data->floor_color_arr)
		return (1);
	if (!data->cieling_color_arr)
		return (1);
	return (0);
}

int	check_map_name(char *name)
{
	if (!ft_strnstr(name, ".cub", ft_strlen(name)) || count(name, '.') != 1)
		return (1);
	return (0);
}

void	init(t_data *data)
{
	data->map = NULL;
	data->cieling_color_arr = NULL;
	data->floor_color_arr = NULL;
	data->east_text = NULL;
	data->north_text = NULL;
	data->south_text = NULL;
	data->west_text = NULL;
}

void	parse(t_data *data, int ac, char **av)
{
	if (ac != 2)
		error("invalid argument number");
	if (check_map_name(av[1]) == 1)
		error("invalid map name");
	init(data);
	fill_info(data, av[1], 0);
	parse_map(data);
}
