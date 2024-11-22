/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resizableArray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:15:38 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/22 17:58:20 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	init_arr(t_resizable_arr	*arr, size_t type_size)
{
	if (!arr || type_size == 0)
		return (false);
	arr->count = 0;
	arr->type_size = type_size;
	arr->data = malloc(type_size);
	if (arr->data == NULL)
		return (false);
	arr->max_count = 1;
	return (true);
}

bool	insert_arr(t_resizable_arr	*arr, void *var)
{
	void	*data;

	if (!arr)
		return (false);
	if (arr->max_count <= arr->count)
	{
		arr->max_count *= 2;
		data = malloc(arr->max_count * arr->type_size);
		if (data == NULL)
			return (false);
		ft_memmove(data, arr->data, arr->count * arr->type_size);
		ft_memmove(data + arr->count * arr->type_size, var, arr->type_size);
		free(arr->data);
		arr->count++;
		arr->data = data;
	}
	else
	{
		ft_memmove(arr->data + arr->count * arr->type_size, var,
			arr->type_size);
		arr->count++;
	}
	return (true);
}

bool	free_arr(t_resizable_arr	*arr)
{
	if (arr != NULL && arr->data != NULL)
		free(arr->data);
	return (true);
}
