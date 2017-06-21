/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_param.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 11:47:49 by oshudria          #+#    #+#             */
/*   Updated: 2017/02/24 14:41:30 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_usage(void)
{
	ft_putendl("usage: ./fractol [fractals name] [number of color scheme]");
	ft_putstr("    you may set one or two fractals among : ");
	ft_putendl("mandelbrot, julia, burning ship, spider, julia_x");
	ft_putendl("    color scheme: 1 - 4");
	exit(1);
}

void	ft_puterror(int param)
{
	ft_putstr(RED_PRINT_ON);
	ft_putstr("bad ");
	if (param == 1)
		ft_putstr("first ");
	else if (param == 2)
		ft_putstr("second ");
	else if (param == 3)
		ft_putstr("third ");
	ft_putendl("param");
	ft_putstr(RED_PRINT_OFF);
	ft_print_usage();
}

char	*fractal_name(char *name)
{
	char	*tmp;

	tmp = name;
	while (*tmp)
	{
		*tmp = ft_tolower(*tmp);
		tmp++;
	}
	if (ft_strcmp(name, "mandelbrot") == 0 || ft_strcmp(name, "m") == 0)
		return ("mandelbrot");
	if (ft_strcmp(name, "julia") == 0 || ft_strcmp(name, "j") == 0)
		return ("julia");
	if (ft_strcmp(name, "burning ship") == 0 || ft_strcmp(name, "b") == 0)
		return ("burning ship");
	if (ft_strcmp(name, "spider") == 0 || ft_strcmp(name, "s") == 0)
		return ("spider");
	if (ft_strcmp(name, "julia_x") == 0)
		return ("x_fractal");
	else
		return (NULL);
}

int		fractal_color(char *color_scheme)
{
	if (*color_scheme < '1' || *color_scheme > '4' ||
		!ft_isnumber(color_scheme))
		return (-1);
	return (ft_atoi(color_scheme) - 1);
}
