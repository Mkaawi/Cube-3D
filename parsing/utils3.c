/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:03:39 by abdennac          #+#    #+#             */
/*   Updated: 2025/04/16 22:32:49 by abdennac         ###   ########.fr       */
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
