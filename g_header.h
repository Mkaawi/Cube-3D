/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_header.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:50:47 by amaaouni          #+#    #+#             */
/*   Updated: 2025/04/16 22:27:07 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_HEADER_H
# define G_HEADER_H

# include "cube.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char	**map;
	int		cieling_color;
	int		floor_color;
	int		*cieling_color_arr;
	int		*floor_color_arr;
	char	*north_text;
	char	*south_text;
	char	*west_text;
	char	*east_text;
}			t_data;

void		parse(t_data *data, int ac, char **av);
void		parse_map(t_data *data);
void		fill_info(t_data *data, char *name, int i);
int			check_dub_map(char **arr, int i, int is_map);
int			get_map_line_count(char **tmp);
void		cpy_info(char *F, char *C, t_data *data);
int			info_check(t_data *data);
void		split_info(t_data *data);
void		split_info2(t_data *data);
int			*split_info3(char *str, t_data *data);
int			count(char *arr, char c);
int			ft_strlen2(char **str);
void		ft_free(char **ptr);
char		*ft_strdup_no_newline(const char *src);
int			parse_ints(int *arr);
int			parse_ints2(char *str);
int			rgb_to_hex(int r, int g, int b);
void		getcf(t_data *data);
void		init(t_data *data);
void		free_stuff(t_data *data);
void		error(char *msg);
void		error2(char *str, t_data *data);
void		getcf(t_data *data);
void		print_map(char **map);
char		**ft_split_first_space(const char *str);
int			is_map_component(char *str);

#endif
