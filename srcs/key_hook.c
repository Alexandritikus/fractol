/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:16:53 by oshudria          #+#    #+#             */
/*   Updated: 2017/02/24 14:07:04 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_iterate(t_win *env, int key)
{
	if (key == PAGE_UP)
		env->f->max_iter += 10;
	else if (env->f->max_iter > 10)
		env->f->max_iter -= 10;
}

static void	julia_key_two(t_win *env, int key)
{
	if (key == F5)
	{
		env->f->cx = -0.70176;
		env->f->cy = -0.3842;
	}
	else if (key == F6)
	{
		env->f->cx = -0.835;
		env->f->cy = 0.2321;
	}
	else if (key == F7)
	{
		env->f->cx = -0.8;
		env->f->cy = 0.156;
	}
	else if (key == F8)
	{
		env->f->cx = -0.7269;
		env->f->cy = 0.1889;
	}
	else if (key == F9)
	{
		env->f->cx = 0;
		env->f->cy = -0.8;
	}
}

static void	julia_key(t_win *env, int key)
{
	if (key == KEY_I)
		env->motion_key = (env->motion_key == 0 ? 1 : 0);
	else if (key == F1)
	{
		env->f->cx = -0.4;
		env->f->cy = 0.6;
	}
	else if (key == F2)
	{
		env->f->cx = 0.285;
		env->f->cy = 0;
	}
	else if (key == F3)
	{
		env->f->cx = 0.285;
		env->f->cy = 0.01;
	}
	else if (key == F4)
	{
		env->f->cx = 0.45;
		env->f->cy = 0.1428;
	}
	else
		julia_key_two(env, key);
}

int			key_hook(int key, t_win *env)
{
	if (key == ESC)
		ft_del_win(&env);
	else if (key == UP || key == DOWN || key == RIGHT || key == LEFT)
		move(env, key);
	else if (key == PLUS || key == MINUS)
		zoom_key(env, key);
	else if (key == PAGE_UP || key == PAGE_DOWN)
		set_iterate(env, key);
	else if (key == KEY_R)
		reset_fractal(env);
	else if (key == ONE || key == TWO || key == THREE || key == FOUR)
		change_color_scheme(env, key);
	else if (env->color_scheme == 3 && (key == KEY_Q || key == KEY_W ||
			key == KEY_E || key == KEY_A || key == KEY_S || key == KEY_D))
		change_color_coef(env, key);
	else if (key == ONE_ || key == TWO_ || key == THREE_ ||
			key == FOUR_ || key == FIVE_)
		switch_fractal(env, key);
	else if (env->f->name[0] == 'j' || env->f->name[0] == 'x')
		julia_key(env, key);
	expose_hook(env);
	return (0);
}
