/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapUtils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 00:52:44 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/23 18:12:06 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_zlimits(t_map *map, float *max, float *min)
{
	size_t	i;

	i = 0;
	*max = map->pts[0].z;
	*min = map->pts[0].z;
	while (i < map->height * map->width)
	{
		if (map->pts[i].z > *max)
			*max = map->pts[i].z;
		if (map->pts[i].z < *min)
			*min = map->pts[i].z;
		i++;
	}
}

static bool	apply_terrain(t_map *map)
{
	size_t	i;
	float	max;
	float	min;

	i = 0;
	get_zlimits(map, &max, &min);
	while (i < map->height * map->width)
	{
		map->pts[i].color.val = BLACK;
		if (map->pts[i].z <= 0)
			map->pts[i].color.b = (map->pts[i].z - min) * (155) / (-min);
		if (min > -10 && map->pts[i].z <= 0)
			map->pts[i].color.b = 155;
		if (map->pts[i].z > 0)
			map->pts[i].color.g = 200;
		if (map->pts[i].z > max / 10 && max > 0)
			map->pts[i].color.g = 140;
		if (map->pts[i].z > max / 6 && max > 0)
			map->pts[i].color.val = MOUNTAIN_BROWN;
		if (map->pts[i].z > max / 2 && max > 0)
			map->pts[i].color.val = WHITE;
		i++;
	}
}

bool	colorize_map(t_map *map)
{
	float	max;
	float	min;

	if (map->clr_prof == NONE)
		return (true);
	if (map->clr_prof == TERRAIN)
		return (apply_terrain(map));
}
