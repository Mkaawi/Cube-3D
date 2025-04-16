/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:36:07 by abdennac          #+#    #+#             */
/*   Updated: 2025/04/16 23:34:29 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

int	is_map_component(char *str)
{
	if (ft_strchr(str, '1') || ft_strchr(str, '0'))
		return (1);
	if (ft_strchr(str, 'S') || ft_strchr(str, 'E'))
		return (1);
	if (ft_strchr(str, 'N') || ft_strchr(str, 'W'))
		return (1);
	return (0);
}

void	get_map(char **tmp, t_data *data)
{
	int	i;
	int	j;
	int	map_line_count;

	i = -1;
	j = -1;
	map_line_count = 0;
	map_line_count = get_map_line_count(tmp);
	if (map_line_count < 1)
		error2("no map found", data);
	data->map = malloc(sizeof(char *) * (map_line_count + 1));
	if (!data->map)
		return ;
	while (tmp[++i])
	{
		if (is_map_component(tmp[i]) && !(ft_strnstr(tmp[i], "F ", 2)
				|| ft_strnstr(tmp[i], "C ", 2) || ft_strnstr(tmp[i], "NO", 2)
				|| ft_strnstr(tmp[i], "EA", 2) || ft_strnstr(tmp[i], "WE", 2)
				|| ft_strnstr(tmp[i], "SO", 2)))
			data->map[++j] = ft_strdup_no_newline(tmp[i]);
	}
	if (j >= 0)
		data->map[j + 1] = NULL;
	ft_free(tmp);
}

void	get_map_info(char **tmp, t_data *data, int i)
{
	char	*c;
	char	*f;

	while (tmp[++i])
	{
		if (ft_strchr(tmp[i], '1') && !(ft_strnstr(tmp[i], "F ", 2)
				|| ft_strnstr(tmp[i], "C ", 2) || ft_strnstr(tmp[i], "NO", 2)
				|| ft_strnstr(tmp[i], "EA", 2) || ft_strnstr(tmp[i], "WE", 2)
				|| ft_strnstr(tmp[i], "SO", 2)))
			break ;
		if (ft_strnstr(tmp[i], "NO", 2))
			data->north_text = ft_strdup_no_newline(tmp[i]);
		else if (ft_strnstr(tmp[i], "SO", 2))
			data->south_text = ft_strdup_no_newline(tmp[i]);
		else if (ft_strnstr(tmp[i], "WE", 2))
			data->west_text = ft_strdup_no_newline(tmp[i]);
		else if (ft_strnstr(tmp[i], "EA", 2))
			data->east_text = ft_strdup_no_newline(tmp[i]);
		else if (ft_strnstr(tmp[i], "F ", 2))
			f = ft_strdup_no_newline(tmp[i]);
		else if (ft_strnstr(tmp[i], "C ", 2))
			c = ft_strdup_no_newline(tmp[i]);
	}
	split_info(data);
	cpy_info(f, c, data);
}

void	fill_info(t_data *data, char *name, int i)
{
	char	**tmp;
	int		fd;

	tmp = malloc(1000 * sizeof(char *));
	fd = open(name, O_RDONLY);
	if (fd < 0)
		error("Failed to open file");
	tmp[i] = get_next_line(fd);
	while (tmp[i])
		tmp[++i] = get_next_line(fd);
	tmp[i] = NULL;
	close(fd);
	if (check_dub_map(tmp, 0, 0) == 1)
	{
		ft_free(tmp);
		error("map error");
	}
	get_map_info(tmp, data, -1);
	getcf(data);
	if (info_check(data) == 1)
	{
		ft_free(tmp);
		error2("map info error", data);
	}
	get_map(tmp, data);
}
