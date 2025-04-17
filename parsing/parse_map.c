/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:27:59 by abdennac          #+#    #+#             */
/*   Updated: 2025/04/17 15:37:31 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

int	dub_check(char *arr)
{
	if (ft_strnstr(arr, "NO", 2) || ft_strnstr(arr, "SO", 2) || ft_strnstr(arr,
			"WE", 2) || ft_strnstr(arr, "EA", 2) || ft_strnstr(arr, "F ", 2)
		|| ft_strnstr(arr, "C ", 2))
		return (1);
	return (0);
}

int	check_dub_map(char **arr, int i)
{
	int	map_started;
	int	map_ended;

	map_started = 0;
	map_ended = 0;
	while (arr[i])
	{
		if (dub_check(arr[i]) == 1)
		{
			if (map_started)
				map_ended = 1;
			i++;
			continue ;
		}
		if (is_map_line(arr[i]))
		{
			if (map_ended)
				return (1);
			map_started = 1;
		}
		else if (map_started)
			map_ended = 1;
		i++;
	}
	return (0);
}

int	check_player(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'N')
				count++;
		}
	}
	if (count != 1)
		return (1);
	return (0);
}

int	check_map_borders(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || is_player(map[i][j]))
			{
				if (i == 0 || !map[i + 1] || j == 0 || map[i][j + 1] == '\0'
					|| (map[i - 1][j] != '0' && map[i - 1][j] != '1'
						&& !is_player(map[i - 1][j])) || (map[i + 1][j] != '0'
						&& map[i + 1][j] != '1' && !is_player(map[i + 1][j]))
					|| (map[i][j - 1] != '0' && map[i][j - 1] != '1'
						&& !is_player(map[i][j - 1])) || (map[i][j + 1] != '0'
						&& map[i][j + 1] != '1' && !is_player(map[i][j + 1])))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	parse_map(t_data *data)
{
	if (check_player(data->map) != 0)
		error2("player count error", data);
	if (check_map_borders(data->map) != 0)
		error2("map borders error", data);
}
