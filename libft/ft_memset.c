/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:56:27 by abdennac          #+#    #+#             */
/*   Updated: 2023/12/30 13:04:00 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	char	*p;
	int		i;

	p = ptr;
	i = 0;
	while (n > (size_t)i)
	{
		p[i] = (unsigned char)x;
		i++;
	}
	return (ptr);
}
