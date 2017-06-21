/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 10:59:25 by oshudria          #+#    #+#             */
/*   Updated: 2017/02/23 15:28:17 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fill_julia(t_win *env, t_fract_param s)
{
	int		k;
	int		color;

	k = -1;
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

void		julia(t_win *env, t_pixel start, t_pixel finish)
{
	t_fract_param	s;

	s.cx = env->f->cx;
	s.cy = env->f->cy;
	s.y = start.y - 1;
	while (++(s.y) <= finish.y)
	{
		s.x = start.x - 1;
		while (++(s.x) <= finish.x)
		{
			s.zx = (double)s.x / SW_F * (env->f->rmax - env->f->rmin) +
				env->f->rmin;
			s.zy = (double)s.y / SH * (env->f->imin - env->f->imax) +
				env->f->imax;
			fill_julia(env, s);
		}
	}
}
