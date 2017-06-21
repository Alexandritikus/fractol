/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fractal_param.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:15:07 by oshudria          #+#    #+#             */
/*   Updated: 2017/02/24 14:20:48 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	get_fractal_size(char name, int size_type)
{
	int				f;
	const double	rmax[3] = {2.25, 2.5, 3.5};
	const double	rmin[3] = {-2.75, -2.5, -3.5};
	const double	imax[3] = {2.0, 2.0, 3.0};
	const double	imin[3] = {-2.0, -2.0, -3.0};

	if (name == 'm' || name == 's')
		f = 0;
	else if (name == 'j' || name == 'x')
		f = 1;
	else
		f = 2;
	if (size_type == 0)
		return (rmin[f]);
	else if (size_type == 1)
		return (rmax[f]);
	else if (size_type == 2)
		return (imin[f]);
	return (imax[f]);
}

int		get_fractal(t_win *env, t_pixel start, t_pixel finish)
{
	if (env->f->name[0] == 'm')
		mandelbrot(env, start, finish);
	else if (env->f->name[0] == 'j')
		julia(env, start, finish);
	else if (env->f->name[0] == 'b')
		burning_ship(env, start, finish);
	else if (env->f->name[0] == 's')
		spider(env, start, finish);
	else if (env->f->name[0] == 'x')
		julia_x(env, start, finish);
	else
		return (0);
	return (1);
}
