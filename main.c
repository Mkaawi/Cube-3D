/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:02:50 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/16 23:24:23 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_header.h"

void	print_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		printf("%s\n", map[y]);
		y++;
	}
}
void ff()
{
	system("leaks -q moraba3");
}
int	main(int ac, char **av)
{
	t_data	*data;

	atexit(ff);
	data = malloc(sizeof(t_data));
	parse(data, ac, av);
	print_map(data->map);
	raycasting_entry(data);
	free_stuff(data);
}
