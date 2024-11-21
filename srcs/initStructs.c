/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initStructs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:28:00 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/21 20:43:00 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	init_arr(t_resizable_arr	*arr, size_t type_size);
bool	insert_arr(t_resizable_arr	*arr, void *var);
bool	free_arr(t_resizable_arr	*arr);

void	init_resizable_arr(t_resizable_arr *arr)
{
	arr->init = init_arr;
	arr->insert = insert_arr;
	arr->free = free_arr;
}

bool	parser(t_map *map, const char *path);

void	init_map(t_map	*map)
{
	map->width = 0;
	map->height = 0;
	map->parse = parser;
}
