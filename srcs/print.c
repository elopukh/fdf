/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 14:52:30 by elopukh           #+#    #+#             */
/*   Updated: 2018/06/22 14:52:32 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	printmap(t_vect **matrix, t_window *win)
{
	int i;
	int j;

	i = 0;
	while (i < win->height)
	{
		j = 0;
		while (j < win->width)
		{
			if ((i + 1) < win->height)
			{
				bresen(xyztoxy(matrix[i][j], win),
				xyztoxy(matrix[i + 1][j], win), win);
			}
			if ((j + 1) < win->width)
				bresen(xyztoxy(matrix[i][j], win),
				xyztoxy(matrix[i][j + 1], win), win);
			j++;
		}
		i++;
	}
}

void	povorot(t_window *win, char c, int sign)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	if (c == 'y' && sign == 1)
		win->dy += 0.1;
	if (c == 'y' && sign == -1)
		win->dy -= 0.1;
	if (c == 'x' && sign == 1)
		win->dx += 0.1;
	if (c == 'x' && sign == -1)
		win->dx -= 0.1;
	printmap(win->matrix, win);
}

void	sdvig(t_window *win, int sx, int sy)
{
	int i;
	int j;

	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	i = 0;
	while (i < win->height)
	{
		j = 0;
		while (j < win->width)
		{
			win->matrix[i][j].x += sx;
			win->matrix[i][j].y += sy;
			j++;
		}
		i++;
	}
	printmap(win->matrix, win);
}

void	countz(int sign, t_window *win)
{
	int i;
	int j;

	i = 0;
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	while (i < win->height)
	{
		j = 0;
		while (j < win->width)
		{
			if (sign == 1)
				win->matrix[i][j].z *= 1.1;
			if (sign == -1)
				win->matrix[i][j].z *= 0.9;
			j++;
		}
		i++;
	}
	printmap(win->matrix, win);
}
