/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 18:19:35 by elopukh           #+#    #+#             */
/*   Updated: 2018/06/02 18:19:38 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./minilibx/mlx.h"
# include <math.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdio.h>
# define H_WIN 1500
# define W_WIN 1500

typedef double	t_dot3 __attribute__((vector_size(sizeof(double)*3)));
typedef double	t_dot2 __attribute__((vector_size(sizeof(double)*2)));

typedef struct	s_vect
{
	int			x;
	int			y;
	int			z;
	int			colour;
}				t_vect;

typedef struct
{
	int			height;
	int			width;
	void		*mlx_ptr;
	void		*win_ptr;
	double		dx;
	double		dy;
	double		dz;
	t_vect		**matrix;
}				t_window;

t_vect			xyztoxy(t_vect vect, t_window *win);
int				atoi_base(char *str);
int				count_numb(char *str);
void			bresen(t_vect dot1, t_vect dot2, t_window *win);
void			dealwz(int key, t_window *win);
void			povorot(t_window *win, char c, int sign);
void			sdvig(t_window *win, int sx, int sy);
void			printmap(t_vect **matrix, t_window *win);
char			**readff(char *file);
int				get_matr(char *str, t_window *win);
void			change(t_window *win, int i, int j, int delta_color);
void			countz(int sign, t_window *win);
int				valid(char *str);
#endif
