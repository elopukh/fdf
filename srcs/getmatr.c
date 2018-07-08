/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmatr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:15:57 by elopukh           #+#    #+#             */
/*   Updated: 2018/06/22 16:15:58 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_width(char **matr)
{
	int i;
	int chis;
	int count;

	i = 0;
	chis = -1;
	while (matr[i] != '\0')
	{
		count = count_numb(matr[i]);
		if (chis == -1)
			chis = count;
		if (chis != count)
		{
			return (0);
		}
		count = 0;
		i++;
	}
	return (1);
}

void	count_h(char **str, t_window *win)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		win->height += 1;
		i++;
	}
}

void	fill1(t_window *win, char *str, int i, int j)
{
	char **tmp_1;

	tmp_1 = ft_strsplit(str, ',');
	win->matrix[i][j].x = j * (W_WIN / win->width) / 1.5 +
	(W_WIN - win->width * (W_WIN / win->width) / 1.5) / 2;
	win->matrix[i][j].y = i * (H_WIN / win->height) / 1.5 +
	(H_WIN - win->height * (H_WIN / win->height) / 1.5) / 2;
	win->matrix[i][j].z = ft_atoi(str) * 5;
	if (tmp_1[1])
	{
		win->matrix[i][j].colour = atoi_base(tmp_1[1]);
		free(tmp_1[1]);
	}
	else
		win->matrix[i][j].colour = 16777215;
	free(tmp_1[0]);
	free(str);
	free(tmp_1);
}

void	fill_matr(t_window *win, char **matr)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	while (matr[i] != '\0')
	{
		win->matrix[i] = (t_vect*)malloc(sizeof(t_vect) * win->width);
		tmp = ft_strsplit(matr[i], ' ');
		free(matr[i]);
		j = 0;
		while (tmp[j] != '\0')
		{
			fill1(win, tmp[j], i, j);
			j++;
		}
		free(tmp);
		i++;
	}
	free(matr);
}

int		get_matr(char *str, t_window *win)
{
	char **matr;

	matr = readff(str);
	if (!matr || !check_width(matr))
		return (0);
	count_h(matr, win);
	win->width = count_numb(matr[0]);
	win->matrix = (t_vect**)malloc(sizeof(t_vect*) * win->height);
	fill_matr(win, matr);
	return (1);
}
