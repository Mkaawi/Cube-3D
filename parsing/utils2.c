/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:46:50 by abdennac          #+#    #+#             */
/*   Updated: 2025/04/16 23:23:01 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

void	ft_free(char **ptr)
{
	int	i;

	i = -1;
	if (!ptr)
		return ;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
	ptr = NULL;
}

void	free_c_f(t_data *data)
{
	if (data->cieling_color_arr)
	{
		free(data->cieling_color_arr);
		data->cieling_color_arr = NULL;
	}
	if (data->floor_color_arr)
	{
		free(data->floor_color_arr);
		data->floor_color_arr = NULL;
	}
	if (data)
	{
		free(data);
		data = NULL;
	}
}

void	free_stuff(t_data *data)
{
	if (data->north_text)
	{
		free(data->north_text);
		data->north_text = NULL;
	}
	if (data->south_text)
	{
		free(data->south_text);
		data->south_text = NULL;
	}
	if (data->west_text)
	{
		free(data->west_text);
		data->west_text = NULL;
	}
	if (data->east_text)
	{
		free(data->east_text);
		data->east_text = NULL;
	}
	if (data->map)
		ft_free(data->map);
	free_c_f(data);
}

void	cpy_info(char *f, char *c, t_data *data)
{
	if (f)
	{
		data->floor_color_arr = split_info3(f, data);
		free(f);
	}
	if (c)
	{
		data->cieling_color_arr = split_info3(c, data);
		free(c);
	}
}
