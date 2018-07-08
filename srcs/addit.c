/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:05:04 by elopukh           #+#    #+#             */
/*   Updated: 2018/06/22 17:05:06 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change(t_window *win, int i, int j, int delta_color)
{
	if (win->matrix[i][j].z > 0)
		win->matrix[i][j].colour = delta_color * win->matrix[i][j].z;
	else
		win->matrix[i][j].colour = delta_color;
}

void	dealwz(int key, t_window *win)
{
	if (key == 6)
		countz(1, win);
	if (key == 7)
		countz(-1, win);
}

int		count_numb(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != ' ' && str[i] != '\0')
		{
			while (str[i] != ' ' && str[i] != '\0')
				i++;
			count++;
		}
	}
	return (count);
}

void	bresen(t_vect dot1, t_vect dot2, t_window *win)
{
	double x;
	double y;

	x = dot1.x;
	y = dot1.y;
	if (abs(dot1.x - dot2.x) > abs(dot1.y - dot2.y))
	{
		while (dot1.x > dot2.x ? x > dot2.x : x < dot2.x)
		{
			x > dot2.x ? x-- : x++;
			y = (int)(((x - dot1.x) / (dot2.x - dot1.x)) * (dot2.y -
														dot1.y) + dot1.y);
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, dot2.colour);
		}
	}
	else
	{
		while (dot1.y > dot2.y ? y > dot2.y : y < dot2.y)
		{
			y > dot2.y ? y-- : y++;
			x = (int)(((y - dot1.y) * (dot2.x - dot1.x) /
											(dot2.y - dot1.y)) + dot1.x);
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, dot2.colour);
		}
	}
}
