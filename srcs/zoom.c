/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 21:22:10 by oshudria          #+#    #+#             */
/*   Updated: 2017/02/23 13:38:26 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_in(t_win *env)
{
	if (env->f->rmax - env->f->rmin >= env->f->x_zoom * 2 &&
		env->f->imax - env->f->imin >= env->f->y_zoom * 2)
	{
		env->f->rmin += env->f->x_zoom;
		env->f->rmax -= env->f->x_zoom;
		env->f->imin += env->f->y_zoom;
		env->f->imax -= env->f->y_zoom;
	}
}

static void	zoom_out(t_win *env)
{
	env->f->rmin -= env->f->x_zoom;
	env->f->rmax += env->f->x_zoom;
	env->f->imin -= env->f->y_zoom;
	env->f->imax += env->f->y_zoom;
}

void		zoom_mouse(t_win *env, int key, int x, int y)
{
	double	px1;
	double	py1;
	double	px2;
	double	py2;

	px1 = (double)x / SW_F * (env->f->rmax - env->f->rmin) + env->f->rmin;
	py1 = (double)y / SH * (env->f->imin - env->f->imax) + env->f->imax;
	if (key == M_S_UP)
		zoom_in(env);
	else if (key == M_S_DOWN)
		zoom_out(env);
	px2 = (double)x / SW_F * (env->f->rmax - env->f->rmin) + env->f->rmin;
	py2 = (double)y / SH * (env->f->imin - env->f->imax) + env->f->imax;
	env->f->rmin += (px1 - px2);
	env->f->rmax += (px1 - px2);
	env->f->imin += (py1 - py2);
	env->f->imax += (py1 - py2);
	update_zoom_shift(env->f);
}

void		zoom_key(t_win *env, int key)
{
	if (key == PLUS)
		zoom_in(env);
	if (key == MINUS)
		zoom_out(env);
	update_zoom_shift(env->f);
}
