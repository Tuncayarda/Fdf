/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapUtils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:19:45 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/22 21:35:33 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_rot_matrix(float matrix[4][4], float x, float y, float z);

void	set_angles(t_map *map)
{
	if (map->proj == ISOMETRIC)
	{
		map->angle_x = 35;
		map->angle_y = -45;
		map->angle_z = 0;
	}
	if (map->proj == DIMETRIC)
	{
		map->angle_x = 42;
		map->angle_y = 7;
		map->angle_z = 0;
	}
	if (map->proj == TRIMETRIC)
	{
		map->angle_x = 45;
		map->angle_y = 30;
		map->angle_z = 60;
	}
}

float	degto_rad(float angle)
{
	return (angle * (PI / 180));	
}

bool	scale_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->width * map->height)
	{
		map->pts[i].x *= map->scale_val;
		map->pts[i].y *= map->scale_val;
		map->pts[i].z *= (map->scale_val / map->z_div);
		i++;
	}
	return (true);
}

bool	push_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->width * map->height)
	{
		map->pts[i].x += map->x_offset;
		map->pts[i].y += map->y_offset;
		i++;
	}
	return (true);
}

bool	rotate_map(t_map *map)
{
	size_t	i;
	float	x_new;
	float	y_new;
	float	matrix[4][4];

	set_angles(map);
	init_rot_matrix(matrix, degto_rad(map->angle_x),
		degto_rad(map->angle_y), degto_rad(map->angle_z));
	i = 0;
	while (i < map->width * map->height)
	{
		x_new = matrix[0][0] * map->pts[i].x + matrix[0][1]
		* map->pts[i].y + matrix[0][2] * map->pts[i].z + matrix[0][3];
		y_new = matrix[1][0] * map->pts[i].x + matrix[1][1]
		* map->pts[i].y + matrix[1][2] * map->pts[i].z + matrix[1][3];
		map->pts[i].x = x_new;
		map->pts[i].y = y_new;
		i++;
	}
	return (true);
}
