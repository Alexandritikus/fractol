/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 10:56:42 by oshudria          #+#    #+#             */
/*   Updated: 2017/02/23 15:35:28 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fill_mandelbrot(t_win *env, t_fract_param s)
{
	int		k;
	int		color;
	double	cardio;

	k = -1;
	cardio = sqrt((s.cx - 0.25) * (s.cx - 0.25) + s.cy * s.cy);
	if (s.cx >= (cardio - 2 * cardio * cardio + 0.25) ||
		(s.cx + 1) * (s.cx + 1) + s.cy * s.cy >= 0.0625)
	{
		while (++k < env->f->max_iter && (s.zx * s.zx + s.zy * s.zy) < 4)
		{
			s.tz = s.zx * s.zx - s.zy * s.zy;
			s.zy = 2 * s.zx * s.zy;
			s.zx = s.tz;
			s.zx = s.zx + s.cx;
			s.zy = s.zy + s.cy;
		}
		if (k < env->f->max_iter)
		{
			color = ft_getcolor(k, env);
			ft_memcpy(&(env->p->adr[s.x * 4 + env->p->sl * s.y]), &color, 4);
		}
	}
}

void		mandelbrot(t_win *env, t_pixel start, t_pixel finish)
{
	t_fract_param	s;

	s.y = start.y - 1;
	while (++(s.y) <= finish.y)
	{
		s.x = start.x - 1;
		while (++(s.x) <= finish.x)
		{
			s.zx = 0;
			s.zy = 0;
			s.cx = (double)s.x / SW_F * (env->f->rmax - env->f->rmin) +
				env->f->rmin;
			s.cy = (double)s.y / SH * (env->f->imin - env->f->imax) +
				env->f->imax;
			fill_mandelbrot(env, s);
		}
	}
}
