/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:19:21 by abdennac          #+#    #+#             */
/*   Updated: 2025/04/16 20:50:31 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char *str, char c)
{
	int	count;
	int	i;

	if (!str)
		return (0);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	fre(char **str, int count)
{
	int	i;

	i = 0;
	while (i <= count)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	**cpy(char **new, char *s, char c)
{
	int	start;
	int	end;
	int	dp;

	start = 0;
	end = 0;
	dp = 0;
	while (dp < count((char *)s, c))
	{
		while (s[start] == c)
			start++;
		end = start + 1;
		while (s[end] != c && s[end])
			end++;
		new[dp] = ft_substr(s, start, end - start);
		if (new[dp] == NULL)
		{
			fre(new, count((char *)s, c));
			return (NULL);
		}
		start = end + 1;
		dp++;
	}
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = ft_calloc(count((char *)s, c) + 1, sizeof(char **));
	if (!str)
		return (NULL);
	str = cpy((char **)str, (char *)s, c);
	return (str);
}
