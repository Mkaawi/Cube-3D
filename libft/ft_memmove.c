/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:16:47 by abdennac          #+#    #+#             */
/*   Updated: 2024/01/02 14:00:05 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst1;
	char	*src1;
	int		ilen;

	ilen = (int)len - 1;
	dst1 = (char *)dst;
	src1 = (char *)src;
	i = 0;
	if (src1 == NULL && dst1 == NULL)
		return (0);
	if (src1 <= dst1)
	{
		while (ilen >= 0)
		{
			dst1[ilen] = src1[ilen];
			ilen--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return ((void *)dst1);
}
