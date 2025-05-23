/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:03:39 by abdennac          #+#    #+#             */
/*   Updated: 2025/04/17 19:30:24 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

int	rgb_to_hex(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}

char	**ft_split_first_space(const char *str)
{
	char	**result;
	int		space_pos;

	if (!str)
		return (NULL);
	space_pos = 0;
	while (str[space_pos] && str[space_pos] != ' ')
		space_pos++;
	result = malloc(3 * sizeof(char *));
	if (!result)
		return (NULL);
	result[0] = malloc(space_pos + 1);
	if (!result[0])
		return (free(result), NULL);
	ft_strlcpy(result[0], str, space_pos + 1);
	if (str[space_pos] == ' ')
	{
		result[1] = ft_strdup(str + space_pos + 1);
		if (!result[1])
			return (free(result[0]), free(result), NULL);
	}
	else
		result[1] = NULL;
	result[2] = NULL;
	return (result);
}

int	is_map_line(char *line)
{
	return ((ft_strchr(line, '1') || ft_strchr(line, '0')) && !(ft_strnstr(line,
				"F ", 2) || ft_strnstr(line, "C ", 2) || ft_strnstr(line, "NO",
				2) || ft_strnstr(line, "EA", 2) || ft_strnstr(line, "WE", 2)
			|| ft_strnstr(line, "SO", 2)));
}

int	count_doups(char **line, char *data)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (line[++i])
	{
		if (ft_strnstr(line[i], data, 2))
			count++;
	}
	return (count);
}

int	is_map_info(char *str)
{
	if (ft_strnstr(str, "F ", 2) || ft_strnstr(str, "C ", 2) || ft_strnstr(str,
			"NO", 2) || ft_strnstr(str, "EA", 2) || ft_strnstr(str, "WE", 2)
		|| ft_strnstr(str, "SO", 2))
		return (1);
	return (0);
}
