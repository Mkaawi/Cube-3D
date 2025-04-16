/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:27:59 by abdennac          #+#    #+#             */
/*   Updated: 2025/04/16 22:22:57 by abdennac         ###   ########.fr       */
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

int	check_dub_map(char **arr, int i, int is_map)
{
	while (arr[i])
	{
		if (dub_check(arr[i]) == 1)
		{
			i++;
			continue ;
		}
		if ((ft_strchr(arr[i], '1') || ft_strchr(arr[i], '0'))
			&& !(ft_strnstr(arr[i], "F ", 2) || ft_strnstr(arr[i], "C ", 2)
				|| ft_strnstr(arr[i], "NO", 2) || ft_strnstr(arr[i], "EA", 2)
				|| ft_strnstr(arr[i], "WE", 2) || ft_strnstr(arr[i], "SO", 2)))
		{
			if (is_map)
				return (1);
			is_map = 1;
			while (arr[i] && ft_strchr(arr[i], '1') && !(ft_strnstr(arr[i],
						"F ", 2) || ft_strnstr(arr[i], "C ", 2)))
				i++;
		}
		else if (is_map)
			return (1);
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
			{
				map[i][j] = 'N';
				count++;
			}
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
			if (map[i][j] == '0' || map[i][j] == 'N')
			{
				if (i == 0 || !map[i + 1] || j == 0 || map[i][j + 1] == '\0'
					|| (map[i - 1][j] != '0' && map[i - 1][j] != '1' && map[i
						- 1][j] != 'N') || (map[i + 1][j] != '0' && map[i
						+ 1][j] != '1' && map[i + 1][j] != 'N') || (map[i][j
						- 1] != '0' && map[i][j - 1] != '1' && map[i][j
						- 1] != 'N') || (map[i][j + 1] != '0' && map[i][j
						+ 1] != '1' && map[i][j + 1] != 'N'))
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
