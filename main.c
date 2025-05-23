/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:02:50 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/17 22:18:58 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_header.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	parse(data, ac, av);
	raycasting_entry(data);
	free_stuff(data);
}
