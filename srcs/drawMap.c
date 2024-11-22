/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:54:17 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/22 21:39:15 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	draw_map(t_fdf *fdf, t_map map)
{
	size_t	i;

	i = 0;
	while (i < map.width * map.height)
	{
		if ((i + 1) % map.width != 0)
			draw_line(fdf, map.pts[i], map.pts[i + 1]);
		if (i < map.width * map.height - map.width)
			draw_line(fdf, map.pts[i], map.pts[i + map.width]);
		i++;
	}
	return (true);
}

t_map	copy_map(t_map *map)
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
	return (rtn);
}

t_map	conf_map(t_map *map)
{
	t_map	rtn;

	rtn = copy_map(map);
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
