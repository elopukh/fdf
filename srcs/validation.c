/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:38:55 by elopukh           #+#    #+#             */
/*   Updated: 2018/06/20 13:38:57 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_res(char s, int step)
{
	int a;
	int res;

	if ((s >= 'A' && s <= 'F'))
	{
		s = s - 55;
		a = s;
		res = a * pow(16, step);
	}
	if ((s >= 'a' && s <= 'f'))
	{
		s = s - 87;
		a = s;
		res = a * pow(16, step);
	}
	if (s >= '0' && s <= '9')
	{
		s = s - 48;
		a = s;
		res = a * pow(16, step);
	}
	return (res);
}

int		atoi_base(char *str)
{
	int i;
	int res;
	int step;

	res = 0;
	i = 0;
	if (str[0] == '0' && str[1] == 'x')
		i += 2;
	step = ft_strlen(str) - 3;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'F') ||
			(str[i] >= 'a' && str[i] <= 'f') ||
			(str[i] >= '0' && str[i] <= '9'))
		{
			res += count_res(str[i], step);
			step--;
			i++;
		}
	}
	return (res);
}

int		valid(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'f')
			&& !(str[i] >= 'A' && str[i] <= 'F')
			&& !(str[i] >= '0' && str[i] <= '9')
			&& str[i] != 'x' && str[i] != ' ' && str[i] != ',' && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}
