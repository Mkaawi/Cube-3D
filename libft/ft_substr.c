/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:19:49 by abdennac          #+#    #+#             */
/*   Updated: 2023/12/20 19:10:53 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	j;
	size_t	strsize;
	size_t	to_allocate;

	strsize = ft_strlen(s);
	to_allocate = len;
	if (!(s))
		return (NULL);
	if (start >= strsize || !*s)
		return (ft_strdup(""));
	if (to_allocate > (strsize - start))
		to_allocate = strsize - start;
	sub = (char *)malloc((to_allocate + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	j = 0;
	while (j < to_allocate)
	{
		sub[j] = s[start];
		j++;
		start++;
	}
	sub[j] = '\0';
	return (sub);
}
