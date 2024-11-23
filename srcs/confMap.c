/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:45:33 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/24 00:46:43 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	copy_map(t_map *map)
{
	t_map	rtn;

	rtn.width = map->width;
	rtn.height = map->height;
	rtn.scale_val = map->scale_val;
	rtn.z_div = map->z_div;
	rtn.x_offset = map->x_offset;
	rtn.y_offset = map->y_offset;
	rtn.angle_x = map->angle_x;
	rtn.angle_y = map->angle_y;
	rtn.angle_z = map->angle_z;
	rtn.pts = malloc(sizeof(t_pt) * map->width * map->height);
	ft_memmove(rtn.pts, map->pts, sizeof(t_pt) * map->width * map->height);
	rtn.parse = map->parse;
	rtn.scale = map->scale;
	rtn.push = map->push;
	rtn.rotate = map->rotate;
	rtn.proj = map->proj;
	rtn.clr_prof = map->clr_prof;
	rtn.colorize = map->colorize;
	return (rtn);
}

static t_map	conf_ortho_map(t_map *map)
{
	t_map	rtn;

	rtn = copy_map(map);
	if (!rtn.pts)
		return (rtn);
	rtn.colorize(&rtn);
	rtn.x_offset = -(map->width / 2);
	rtn.y_offset = -(map->height / 2);
	rtn.push(&rtn);
	rtn.scale(&rtn);
	rtn.rotate(&rtn);
	rtn.x_offset = (WIDTH / 2) + map->x_offset;
	rtn.y_offset = (HEIGHT / 2) + map->y_offset;
	rtn.push(&rtn);
	return (rtn);
}

static void	sphere_loop(t_map *map, size_t i)
{
	float	lng;
	float	lat;

	lng = -(map->pts[i].x) * (PI * 2) / (map->width - 1);
	lat = (map->pts[i].y / (float)(map->height - 1)) * PI;
	map->pts[i].x = (map->width / (PI * 2) + map->pts[i].z
			/ map->z_div) * cos(lng) * sin(lat);
	map->pts[i].y = (map->width / (PI * 2) + map->pts[i].z
			/ map->z_div) * sin(lng) * sin(lat);
	map->pts[i].z = (map->width / (PI * 2) + map->pts[i].z
			/ map->z_div) * cos(lat);
}

static t_map	conf_sphere_map(t_map *map)
{
	t_map		rtn;
	size_t		i;

	rtn = copy_map(map);
	i = 0;
	rtn.colorize(&rtn);
	set_invisibles_pos(&rtn);
	while (i < map->height * map->width && rtn.pts != NULL)
	{
		sphere_loop(&rtn, i);
		i++;
	}
	i = 0;
	rtn.rotate(&rtn);
	rtn.scale(&rtn);
	rtn.x_offset = (WIDTH / 2) + map->x_offset;
	rtn.y_offset = (HEIGHT / 2) + map->y_offset;
	rtn.push(&rtn);
	return (rtn);
}

t_map	conf_map(t_map *map)
{
	if (map->proj == SPHERE)
		return (conf_sphere_map(map));
	return (conf_ortho_map(map));
}
