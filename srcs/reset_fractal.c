/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:32:12 by oshudria          #+#    #+#             */
/*   Updated: 2017/02/24 14:46:29 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_fractal(t_win *env)
{
	env->f->rmin = get_fractal_size(env->f->name[0], 0);
	env->f->rmax = get_fractal_size(env->f->name[0], 1);
	env->f->imin = get_fractal_size(env->f->name[0], 2);
	env->f->imax = get_fractal_size(env->f->name[0], 3);
	update_zoom_shift(env->f);
	env->r = BASE_COLOR;
	env->g = BASE_COLOR;
	env->b = BASE_COLOR;
}

int		switch_fractal(t_win *env, int key)
{
	char	*new_name;

	if (key == ONE_)
		new_name = "mandelbrot";
	else if (key == TWO_)
		new_name = "julia";
	else if (key == THREE_)
		new_name = "burning ship";
	else if (key == FOUR_)
		new_name = "spider";
	else if (key == FIVE_)
		new_name = "x_fractal";
	if (ft_strcmp(env->f->name, new_name) == 0)
		return (0);
	env->f->name = new_name;
	env->f->cx = (new_name[0] == 'j' ? -0.4 : -0.047);
	env->f->cy = (new_name[0] == 'j' ? 0.6 : 0.274);
	env->f->rmin = get_fractal_size(env->f->name[0], 0);
	env->f->rmax = get_fractal_size(env->f->name[0], 1);
	env->f->imin = get_fractal_size(env->f->name[0], 2);
	env->f->imax = get_fractal_size(env->f->name[0], 3);
	env->motion_key = 0;
	update_zoom_shift(env->f);
	return (1);
}
