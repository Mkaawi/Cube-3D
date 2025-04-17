/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:47:22 by abdennac          #+#    #+#             */
/*   Updated: 2025/04/17 22:19:16 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

int	parse_ints(int *arr)
{
	if (arr[0] > 255 || arr[0] < 0)
		return (1);
	if (arr[1] > 255 || arr[1] < 0)
		return (1);
	if (arr[2] > 255 || arr[2] < 0)
		return (1);
	return (0);
}

int	parse_ints2(char *str)
{
	int	i;

	i = -1;
	if (count(str, ',') > 2)
		return (1);
	while (str[++i])
	{
		if (str[i] == ',' && (str[i - 1] == ',' || str[i + 1] == ','))
			return (1);
	}
	return (0);
}

int	*split_info3(char *str, t_data *data)
{
	int		*arr;
	char	**split;
	char	**tmp;

	if (parse_ints2(str) != 0)
		error2("ceiling/floor error", data);
	split = ft_split_first_space(str);
	check_split_str(split, data);
	if (!split || !split[1])
		error2("Invalid ceiling/floor format", data);
	tmp = ft_split(split[1], ',');
	if (!tmp || ft_strlen2(tmp) != 3)
		error2("Ceiling/floor color format error", data);
	arr = malloc(3 * sizeof(int));
	arr[0] = ft_atoi(tmp[0]);
	arr[1] = ft_atoi(tmp[1]);
	arr[2] = ft_atoi(tmp[2]);
	ft_free(split);
	ft_free(tmp);
	if (parse_ints(arr) != 0)
		error2("ceiling/floor color out of range", data);
	return (arr);
}

void	split_info2(t_data *data)
{
	char	**split;

	split = ft_split(data->west_text, ' ');
	if (split && split[1])
	{
		free(data->west_text);
		data->west_text = ft_strdup(split[1]);
	}
	check_split(data, split);
	ft_free(split);
	split = ft_split(data->east_text, ' ');
	if (split && split[1])
	{
		free(data->east_text);
		data->east_text = ft_strdup(split[1]);
	}
	check_split(data, split);
	ft_free(split);
}

void	split_info(t_data *data)
{
	char	**split;

	split = ft_split(data->north_text, ' ');
	if (split && split[1])
	{
		free(data->north_text);
		data->north_text = ft_strdup(split[1]);
	}
	check_split(data, split);
	ft_free(split);
	split = ft_split(data->south_text, ' ');
	if (split && split[1])
	{
		free(data->south_text);
		data->south_text = ft_strdup(split[1]);
	}
	check_split(data, split);
	ft_free(split);
	split_info2(data);
}
