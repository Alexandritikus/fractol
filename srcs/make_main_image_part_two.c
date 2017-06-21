/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_main_image_part_two.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 10:30:42 by oshudria          #+#    #+#             */
/*   Updated: 2017/02/23 10:39:23 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*draw_five(void *param)
{
	t_win	*env;
	t_pixel	start;
	t_pixel	finish;

	start.x = 0;
	finish.x = (SW_F / 4) - 1;
	start.y = SH / 2;
	finish.y = SH - 1;
	env = (t_win*)param;
	get_fractal(env, start, finish);
	return (NULL);
}

void	*draw_six(void *param)
{
	t_win	*env;
	t_pixel	start;
	t_pixel	finish;

	start.x = SW_F / 4;
	finish.x = (SW_F / 2) - 1;
	start.y = SH / 2;
	finish.y = SH - 1;
	env = (t_win*)param;
	get_fractal(env, start, finish);
	return (NULL);
}

void	*draw_seven(void *param)
{
	t_win	*env;
	t_pixel	start;
	t_pixel	finish;

	start.x = SW_F / 2;
	finish.x = SW_F - (SW_F / 4) - 1;
	start.y = SH / 2;
	finish.y = SH - 1;
	env = (t_win*)param;
	get_fractal(env, start, finish);
	return (NULL);
}

void	*draw_eight(void *param)
{
	t_win	*env;
	t_pixel	start;
	t_pixel	finish;

	start.x = SW_F - (SW_F / 4);
	finish.x = SW_F - 1;
	start.y = SH / 2;
	finish.y = SH - 1;
	env = (t_win*)param;
	get_fractal(env, start, finish);
	return (NULL);
}
