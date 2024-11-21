/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:54:01 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/21 20:48:13 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int an, char *args[])
{
	t_map	map;


	init_map(&map);
	map.parse(&map, args[1]);
	for (int i = 0; i < map.height; i++)
	{
		for(int j = 0; j < map.width; j++)
		{
			printf("(%.f,%.f,%.f) ", map.pts[(map.width * i) + j].x, map.pts[(map.width * i) + j].y, map.pts[(map.width * i) + j].z);
		}
		printf("\n");
	}
}
