/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:27:59 by abdennac          #+#    #+#             */
/*   Updated: 2025/04/16 20:46:11 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

void	error(char *msg)
{
	if (msg)
		printf("%s\n", msg);
	exit(1);
}

void	error2(char *str, t_data *data)
{
	free_stuff(data);
	error(str);
}

int	count(char *arr, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arr[i])
	{
		if (arr[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	get_map_line_count(char **tmp)
{
	int	i;
	int	map_line_count;

	map_line_count = 0;
	i = -1;
	while (tmp[++i])
	{
		if ((ft_strchr(tmp[i], '1') && !(ft_strnstr(tmp[i], "F ", 2)
					|| ft_strnstr(tmp[i], "C ", 2))) && !(ft_strnstr(tmp[i],
					"NO", 2) || ft_strnstr(tmp[i], "SO", 2)
				|| ft_strnstr(tmp[i], "WE", 2) || ft_strnstr(tmp[i], "EA", 2)
				|| ft_strnstr(tmp[i], "F ", 2) || ft_strnstr(tmp[i], "C ", 2)))
			map_line_count++;
	}
	return (map_line_count);
}

void	getcf(t_data *data)
{
	data->cieling_color = rgb_to_hex(data->cieling_color_arr[0],
			data->cieling_color_arr[1], data->cieling_color_arr[2]);
	data->floor_color = rgb_to_hex(data->floor_color_arr[0],
			data->floor_color_arr[1], data->floor_color_arr[2]);
}
