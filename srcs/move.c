/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 16:44:46 by oshudria          #+#    #+#             */
/*   Updated: 2017/02/23 18:21:49 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(t_win *env, int key)
{
	if (key == UP)
	{
		env->f->imin -= env->f->y_shift;
		env->f->imax -= env->f->y_shift;
	}
	if (key == DOWN)
	{
		env->f->imin += env->f->y_shift;
		env->f->imax += env->f->y_shift;
	}
	if (key == RIGHT)
	{
		env->f->rmin -= env->f->x_shift;
		env->f->rmax -= env->f->x_shift;
	}
	if (key == LEFT)
	{
		env->f->rmin += env->f->x_shift;
		env->f->rmax += env->f->x_shift;
	}
}
