/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:21:10 by abdennac          #+#    #+#             */
/*   Updated: 2025/04/17 22:21:59 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

void	check_split_str(char **str, t_data *data)
{
	int	i;

	i = -1;
	while (str[1][++i])
	{
		if (!ft_isdigit(str[1][i]) && str[1][i] != ',')
			error2("map info error", data);
	}
	if (!ft_strnstr(str[0], "F", 1) && !ft_strnstr(str[0], "C", 1))
		error2("map info error2", data);
}
