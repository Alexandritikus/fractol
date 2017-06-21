/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 21:54:43 by oshudria          #+#    #+#             */
/*   Updated: 2017/02/23 18:21:31 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hook(int x, int y, t_win *env)
{
	if (env->motion_key == 1 && x > 0 && x < SW_F && y > 0 && y < SH)
	{
		env->f->cx = (double)x / SW_F * (env->f->rmax - env->f->rmin) +
			env->f->rmin;
		env->f->cy = (double)y / SH * (env->f->imin - env->f->imax) +
			env->f->imax;
		expose_hook(env);
	}
	return (0);
}

int	mouse_hook(int key, int x, int y, t_win *env)
{
	if (key == M_S_UP || key == M_S_DOWN)
		zoom_mouse(env, key, x, y);
	expose_hook(env);
	return (0);
}
