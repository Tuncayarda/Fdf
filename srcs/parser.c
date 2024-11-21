/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:12:16 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/21 20:48:24 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	**get_trim_pts_line(int fd)
{
	char	*line;
	char	*trim_line;
	char	**pts;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	trim_line = ft_strtrim(line, " \n \t");
	pts = ft_split(trim_line, ' ');
	free(trim_line);
	free(line);
	return (pts);
}

bool	line_loop(char **pts, t_pt *pt, t_resizable_arr *arr, t_map *map)
{
	size_t	x;

	x = 0;
	while (pts[x])
	{
		if (ft_strchr(pts[x], ','))
			pt->color.val = ft_hexatoi(ft_strchr(pts[x], ',') + 1);
		else
			pt->color.val = WHITE;
		pt->x = (float)x;
		pt->y = (float)map->height;
		pt->z = ft_atoi(pts[x]);
		free(pts[x]);
		if (arr->insert(arr, pt) == false)
			return (false);
		x++;
	}
	map->width = x;
	return (true);
}

bool	read_file(t_map *map, int fd)
{
	char			**pts;
	t_resizable_arr	arr;
	t_pt			point;

	init_resizable_arr(&arr);
	arr.init(&arr, sizeof(t_pt));
	if (arr.data == NULL)
		return (false);
	pts = get_trim_pts_line(fd);
	if (pts == NULL)
		return (false);
	while (pts)
	{
		if (line_loop(pts, &point, &arr, map) == false)
			return (false);
		map->height++;
		free(pts);
		pts = get_trim_pts_line(fd);
	}
	map->pts = arr.data;
	return (true);
}

bool	parser(t_map *map, const char *path)
{
	int	fd;

	if (check_file(path) == false)
		return (false);
	fd = open (path, O_RDONLY);
	if (fd == -1)
		return (false);
	if (read_file(map, fd) == false)
		return (false);
	return (true);
}
