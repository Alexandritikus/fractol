/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:46:51 by oshudria          #+#    #+#             */
/*   Updated: 2017/02/24 14:39:35 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	expose_interactions(void *mlx, t_win *env[2])
{
	if (env[0] != NULL)
	{
		mlx_expose_hook(env[0]->win, expose_hook, env[0]);
		mlx_mouse_hook(env[0]->win, mouse_hook, env[0]);
		mlx_key_hook(env[0]->win, key_hook, env[0]);
		mlx_hook(env[0]->win, MNOTIFY, PMMASK, hook, env[0]);
	}
	if (env[1] != NULL)
	{
		mlx_expose_hook(env[1]->win, expose_hook, env[1]);
		mlx_mouse_hook(env[1]->win, mouse_hook, env[1]);
		mlx_key_hook(env[1]->win, key_hook, env[1]);
		mlx_hook(env[1]->win, MNOTIFY, PMMASK, hook, env[1]);
	}
	mlx_loop(mlx);
}

static void	fractol(char *names[2], int color_scheme)
{
	void	*mlx;
	t_win	*env[2];

	mlx = mlx_init();
	env[0] = init_win(names[0], color_scheme, mlx, 1);
	env[1] = init_win(names[1], color_scheme, mlx, 0);
	expose_interactions(mlx, env);
}

int			main(int argc, char **argv)
{
	int		color_scheme;
	char	*names[2];

	color_scheme = 1;
	names[0] = NULL;
	names[1] = NULL;
	if (argc == 1)
		names[0] = "mandelbrot";
	else if (argc > 4)
		ft_print_usage();
	else
	{
		if (!(names[0] = fractal_name(argv[1])))
			ft_puterror(1);
		if (argc > 2 && !(names[1] = fractal_name(argv[2])) &&
			(color_scheme = fractal_color(argv[2])) == -1)
			ft_puterror(2);
		if (argc == 4 && (color_scheme = fractal_color(argv[3])) == -1)
			ft_puterror(3);
	}
	fractol(names, color_scheme);
	return (0);
}
