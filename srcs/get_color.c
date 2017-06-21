/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:38:54 by oshudria          #+#    #+#             */
/*   Updated: 2017/02/24 14:03:36 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static unsigned	int	ft_col_one(int k)
{
	int col[16];

	col[0] = 0x3C1E0F;
	col[1] = 0x19071A;
	col[2] = 0x09012F;
	col[3] = 0x040449;
	col[4] = 0x000764;
	col[5] = 0x0C2C8A;
	col[6] = 0x1852B1;
	col[7] = 0x397DD1;
	col[8] = 0x86B5E5;
	col[9] = 0xD3ECF8;
	col[10] = 0xF1E9BF;
	col[11] = 0xF8C95F;
	col[12] = 0xFFAA00;
	col[13] = 0xCC8000;
	col[14] = 0x995700;
	col[15] = 0x6A3403;
	return (col[k % 16]);
}

static unsigned int	ft_col_two(int k)
{
	int	col[22];

	col[0] = 0xF7484E;
	col[1] = 0xE8EEA4;
	col[2] = 0xB1F4FA;
	col[3] = 0xF9D006;
	col[4] = 0x02E6A1;
	col[5] = 0xDF1B73;
	col[6] = 0xFFFFFF;
	col[7] = 0x233032;
	col[8] = 0x51D386;
	col[9] = 0x183F28;
	col[10] = 0xAF3520;
	col[11] = 0xFBEE23;
	col[12] = 0x5439F7;
	col[13] = 0xF38F64;
	col[14] = 0xB7CABE;
	col[15] = 0xE629F9;
	col[16] = 0x1FD19F;
	col[17] = 0xF04358;
	col[18] = 0x07BBEF;
	col[19] = 0x04C746;
	col[20] = 0x533B0A;
	col[21] = 0x1C6611;
	return (col[k % 22]);
}

unsigned int		ft_getcolor(int k, t_win *env)
{
	unsigned int	color;

	color = 0;
	if (env->color_scheme == 1)
		color = ft_col_one(k);
	else if (env->color_scheme == 2)
		color = ft_col_two(k);
	else if (env->color_scheme == 3)
	{
		color += fabs(cos(env->r * k) * 145 + 110);
		color = color << 8;
		color += fabs(cos(env->g * k) * 145 + 110);
		color = color << 8;
		color += fabs(cos(env->b * k) * 145 + 110);
	}
	else
		color = WHITE;
	return (color);
}

void				change_color_scheme(t_win *env, int key)
{
	if (key == ONE)
		env->color_scheme = 0;
	else if (key == TWO)
		env->color_scheme = 1;
	else if (key == THREE)
		env->color_scheme = 2;
	else if (key == FOUR)
		env->color_scheme = 3;
}

void				change_color_coef(t_win *env, int key)
{
	if (key == KEY_Q)
		env->r += COLOR_SENS;
	else if (key == KEY_A)
		env->r -= COLOR_SENS;
	else if (key == KEY_W)
		env->g += COLOR_SENS;
	else if (key == KEY_S)
		env->g -= COLOR_SENS;
	else if (key == KEY_E)
		env->b += COLOR_SENS;
	else if (key == KEY_D)
		env->b -= COLOR_SENS;
}
