/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setInvisibles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:06:59 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/24 00:49:43 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_invisibles_pos(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height * map->width && map->pts != NULL)
	{
		if ((int)map->angle_y == 0
			&& map->pts[i].x < map->width / 2.0f)
			map->pts[i].is_visible = false;
		else if ((int)map->angle_y == 45
			&& (map->pts[i].x < map->width / 3.0f
				|| map->pts[i].x > map->width / 2.0f + map->width / 3.0f))
			map->pts[i].is_visible = false;
		else if ((int)map->angle_y == 90
			&& (map->pts[i].x < map->width / 4.0f
				|| map->pts[i].x > map->width / 2.0f + map->width / 4.0f))
			map->pts[i].is_visible = false;
		else if ((int)map->angle_y == 135
			&& (map->pts[i].x < map->width / 6.0f
				|| map->pts[i].x > map->width / 2.0f + map->width / 12.0f))
			map->pts[i].is_visible = false;
		else
			map->pts[i].is_visible = true;
		i++;
	}
}
