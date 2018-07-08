/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:42:54 by elopukh           #+#    #+#             */
/*   Updated: 2018/06/23 15:42:55 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	char *str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*str) *
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	free((void *)s1);
	free((void *)s2);
	return (str);
}

char	*readff1(char *tmp, char *str)
{
	char	*tmp_1;

	tmp_1 = ft_strjoinfree(str, tmp);
	str = ft_strdup(tmp_1);
	free(tmp_1);
	tmp = ft_strjoin(str, "\n");
	free(str);
	str = ft_strdup(tmp);
	free(tmp);
	return (str);
}

int		file_open(char *file)
{
	int fd;

	fd = open(file, O_DIRECTORY);
	if (fd > 0)
		return (-1);
	else
		fd = open(file, O_RDONLY);
	return (fd);
}

char	**readff(char *file)
{
	char	*str;
	char	*tmp;
	char	**ret;
	int		fd;

	str = ft_strnew(0);
	tmp = NULL;
	fd = file_open(file);
	if (fd < 0 || fd > 8192)
		return (NULL);
	while (get_next_line(fd, &tmp) == 1)
	{
		if (!valid(tmp))
			return (NULL);
		str = readff1(tmp, str);
	}
	if (ft_strlen(str) == 0 || str[0] == '\n')
		return (NULL);
	ret = ft_strsplit(str, '\n');
	free(tmp);
	free(str);
	return (ret);
}

t_vect	xyztoxy(t_vect vect, t_window *win)
{
	t_vect	tmp;
	int		xc;
	int		yc;
	int		zc;

	xc = win->matrix[(win->height) / 2][(win->width) / 2].x;
	yc = win->matrix[(win->height) / 2][(win->width) / 2].y;
	zc = (win->matrix[(win->height) / 2][(win->width) / 2].z);
	tmp.x = vect.x;
	tmp.y = yc + (vect.y - yc) * cos(win->dx) + (vect.z - zc) * sin(win->dx);
	tmp.z = zc + -((vect.z - zc) * cos(win->dx) - (vect.y - yc) * sin(win->dx));
	vect.x = xc + (tmp.x - xc) * cos(win->dy) - (tmp.z - zc) * sin(win->dy);
	vect.y = tmp.y;
	vect.z = zc + (tmp.z - zc) * cos(win->dy) + (tmp.x - xc) * sin(win->dy);
	tmp.x = xc + (vect.x - xc) * cos(win->dz) + (vect.y - yc) * sin(win->dz);
	tmp.y = yc + (vect.y - yc) * cos(win->dz) - (vect.x - xc) * sin(win->dz);
	tmp.colour = vect.colour;
	return (tmp);
}
