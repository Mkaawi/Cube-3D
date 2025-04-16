/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:19:04 by abdennac          #+#    #+#             */
/*   Updated: 2023/12/29 18:32:46 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long int n)
{
	int	ln;

	ln = 0;
	if (n <= 0)
		ln = 1;
	while (n != 0)
	{
		n = n / 10;
		ln++;
	}
	return (ln);
}

char	*ft_itoa(int n)
{
	int			ln;
	char		*s;
	long int	nb;

	nb = n;
	ln = ft_len(nb);
	s = malloc(sizeof(char) * ln + 1);
	if (!(s))
		return (0);
	s[ln] = 0;
	ln--;
	if (nb == 0)
		s[0] = '0';
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		s[ln] = 48 + (nb % 10);
		nb = nb / 10;
		ln--;
	}
	return (s);
}
