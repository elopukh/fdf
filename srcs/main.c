/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:10:50 by elopukh           #+#    #+#             */
/*   Updated: 2018/05/22 16:11:31 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		max_z1(t_window *win)
{
	int max;
	int i;
	int j;

	i = 0;
	while (i < win->height)
	{
		j = 0;
		while (j < win->width)
		{
			if (i == 0 && j == 0)
				max = win->matrix[i][j].z;
			if (max < win->matrix[i][j].z)
				max = win->matrix[i][j].z;
			j++;
		}
		i++;
	}
	return (max);
}

void	change_colour(t_window *win)
{
	int i;
	int j;
	int delta_color;
	int color_range;
	int max_z;

	i = 0;
	max_z = max_z1(win);
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	color_range = 0xFFFFFF - 0xFF0000;
	if (max_z != 0)
	{
		delta_color = color_range / max_z;
		while (i < win->height)
		{
			j = 0;
			while (j < win->width)
			{
				change(win, i, j, delta_color);
				j++;
			}
			i++;
		}
	}
	printmap(win->matrix, win);
}

int		exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

int		key_handler(int key, void *p)
{
	t_window *win;

	win = (t_window*)p;
	if (key == 53)
		exit(1);
	if (key == 125)
		povorot(win, 'x', 1);
	if (key == 126)
		povorot(win, 'x', -1);
	if (key == 123)
		povorot(win, 'y', 1);
	if (key == 124)
		povorot(win, 'y', -1);
	if (key == 0)
		sdvig(win, -9, 0);
	if (key == 1)
		sdvig(win, 0, 9);
	if (key == 2)
		sdvig(win, 9, 0);
	if (key == 13)
		sdvig(win, 0, -9);
	if (key == 8)
		change_colour(win);
	dealwz(key, win);
	return (1);
}

int		main(int argc, char **argv)
{
	t_window *win;

	if (argc < 2)
		return (0);
	win = (t_window*)malloc(sizeof(t_window));
	win->width = 0;
	win->height = 0;
	win->dx = -0.4;
	win->dy = 0.1;
	win->dz = 0;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, H_WIN, W_WIN, "Its FDF!");
	if (!get_matr(argv[1], win))
	{
		write(1, "Error map!\n", 11);
		return (0);
	}
	printmap(win->matrix, win);
	mlx_hook(win->win_ptr, 2, 1L << 0, key_handler, win);
	mlx_hook(win->win_ptr, 17, 1L << 17, exit_x, win);
	mlx_loop(win->mlx_ptr);
}
