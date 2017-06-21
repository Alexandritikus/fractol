/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 15:55:21 by oshudria          #+#    #+#             */
/*   Updated: 2017/02/24 14:20:01 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_del_win(t_win **env)
{
	int	t;

	t = 0;
	if (*env)
	{
		t = (*env)->title;
		free((*env)->f);
		free((*env)->p);
		mlx_destroy_window((*env)->mlx, (*env)->win);
		free(*env);
		*env = NULL;
	}
	if (t == 1)
		exit(1);
}

void	update_zoom_shift(t_fract *fractal)
{
	fractal->x_zoom = (fractal->rmax - fractal->rmin) / 30;
	fractal->y_zoom = (fractal->imax - fractal->imin) / 30;
	fractal->x_shift = (fractal->rmax - fractal->rmin) / 20;
	fractal->y_shift = (fractal->imax - fractal->imin) / 20;
}

t_pic	*init_pic(void)
{
	t_pic	*pic;

	pic = (t_pic*)malloc(sizeof(t_pic));
	pic->img = NULL;
	pic->adr = NULL;
	pic->bpp = 0;
	pic->sl = 0;
	pic->e = 0;
	return (pic);
}

t_fract	*init_fractal(char *fr_name)
{
	t_fract	*fractal;

	fractal = (t_fract*)malloc(sizeof(t_fract));
	fractal->name = fr_name;
	fractal->rmin = get_fractal_size(fr_name[0], 0);
	fractal->rmax = get_fractal_size(fr_name[0], 1);
	fractal->imin = get_fractal_size(fr_name[0], 2);
	fractal->imax = get_fractal_size(fr_name[0], 3);
	fractal->cx = (fr_name[0] == 'j' ? -0.4 : -0.047);
	fractal->cy = (fr_name[0] == 'j' ? 0.6 : 0.274);
	update_zoom_shift(fractal);
	fractal->max_iter = MAX_ITER;
	return (fractal);
}

t_win	*init_win(char *name, int color_scheme, void *mlx, int t)
{
	t_win	*env;

	env = NULL;
	if (name != NULL)
	{
		env = (t_win*)malloc(sizeof(t_win));
		env->mlx = mlx;
		env->win = mlx_new_window(mlx, SW, SH, "fract'ol");
		env->color_scheme = color_scheme;
		env->r = BASE_COLOR;
		env->g = BASE_COLOR;
		env->b = BASE_COLOR;
		env->f = init_fractal(name);
		env->p = init_pic();
		env->motion_key = 0;
		env->title = t;
	}
	return (env);
}
