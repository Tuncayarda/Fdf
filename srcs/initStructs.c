/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initStructs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:28:00 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/28 23:42:05 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_arr(t_resizable_arr	*arr, size_t type_size);
int	insert_arr(t_resizable_arr	*arr, void *var);
int	free_arr(t_resizable_arr	*arr);

void	init_resizable_arr(t_resizable_arr *arr)
{
	arr->init = init_arr;
	arr->insert = insert_arr;
	arr->free = free_arr;
}

int	parser(t_map *map, const char *path);
int	scale_map(t_map *map);
int	push_map(t_map *map);
int	rotate_map(t_map *map);
int	colorize_map(t_map *map);
int	normalize_map(t_map *map);
int	denormalize_map(t_map *map);

void	init_map(t_map	*map)
{
	map->width = 0;
	map->height = 0;
	map->x_offset = 0;
	map->y_offset = 0;
	map->angle_x = 35;
	map->angle_y = -45;
	map->angle_z = 0;
	map->scale_val = SCALE;
	map->z_div = SCALE;
	map->proj = ISOMETRIC;
	map->clr_prof = NONE;
	map->isfilled = false;
	map->parse = parser;
	map->scale = scale_map;
	map->push = push_map;
	map->rotate = rotate_map;
	map->colorize = colorize_map;
}
