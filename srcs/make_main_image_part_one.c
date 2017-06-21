/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_main_image_part_one.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:28:25 by oshudria          #+#    #+#             */
/*   Updated: 2017/02/23 10:36:42 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*draw_one(void *param)
{
	t_win	*env;
	t_pixel	start;
	t_pixel	finish;

	start.x = 0;
	finish.x = (SW_F / 4) - 1;
	start.y = 0;
	finish.y = (SH / 2) - 1;
	env = (t_win*)param;
	get_fractal(env, start, finish);
	return (NULL);
}

void	*draw_two(void *param)
{
	t_win	*env;
	t_pixel	start;
	t_pixel	finish;

	start.x = SW_F / 4;
	finish.x = (SW_F / 2) - 1;
	start.y = 0;
	finish.y = (SH / 2) - 1;
	env = (t_win*)param;
	get_fractal(env, start, finish);
	return (NULL);
}

void	*draw_three(void *param)
{
	t_win	*env;
	t_pixel	start;
	t_pixel	finish;

	start.x = SW_F / 2;
	finish.x = SW_F - (SW_F / 4) - 1;
	start.y = 0;
	finish.y = (SH / 2) - 1;
	env = (t_win*)param;
	get_fractal(env, start, finish);
	return (NULL);
}

void	*draw_four(void *param)
{
	t_win	*env;
	t_pixel	start;
	t_pixel	finish;

	start.x = SW_F - (SW_F / 4);
	finish.x = SW_F - 1;
	start.y = 0;
	finish.y = (SH / 2) - 1;
	env = (t_win*)param;
	get_fractal(env, start, finish);
	return (NULL);
}
