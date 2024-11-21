/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkFile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:39:33 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/21 21:05:04 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	**get_trim_arr(int fd)
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

static void	check_format(int fd)
{
	char	**pts;
	int		width;
	int		i;

	i = 0;
	pts = get_trim_arr(fd);
	if (!pts)
		terminate("Empty file!!!");
	if (pts)
	{
		while (pts[i])
			i++;
		width = i;
	}
	while (pts)
	{
		i = 0;
		while (pts[i])
			free(pts[i++]);
		free(pts);
		if (i != width)
			terminate("Wrong file format!!!\n");
		pts = get_trim_arr(fd);
	}
}

bool	check_file(const char *path)
{
	int	fd;

	ft_printf("Opening file...\n");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		terminate(NULL);
	ft_printf("Checking map format...\n");
	check_format(fd);
	ft_printf("OK!\n");
	close(fd);
	return (true);
}
