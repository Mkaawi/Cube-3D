/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:27:50 by abdennac          #+#    #+#             */
/*   Updated: 2024/01/02 14:19:03 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	size_t	*new;
	size_t	num;

	num = number * size;
	if (size != 0 && number != num / size)
		return (NULL);
	new = malloc(number * size);
	if (new)
	{
		ft_memset(new, 0, number * size);
		return (new);
	}
	return (NULL);
}
