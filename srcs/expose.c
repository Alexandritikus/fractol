/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:44:48 by oshudria          #+#    #+#             */
/*   Updated: 2017/02/23 17:22:42 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_key_controls(t_win *env)
{
	mlx_string_put(env->mlx, env->win, S_X + 5, S_Y, WHITE, TEXT_01);
	mlx_string_put(env->mlx, env->win, S_X, S_Y * 2, WHITE, TEXT_00);
	mlx_string_put(env->mlx, env->win, S_X, S_Y * 3, WHITE, TEXT_02);
	mlx_string_put(env->mlx, env->win, S_X, S_Y * 4, WHITE, TEXT_03);
	mlx_string_put(env->mlx, env->win, S_X, S_Y * 5, WHITE, TEXT_04);
	mlx_string_put(env->mlx, env->win, S_X, S_Y * 6, WHITE, TEXT_05);
	mlx_string_put(env->mlx, env->win, S_X, S_Y * 7, WHITE, TEXT_06);
	mlx_string_put(env->mlx, env->win, S_X, S_Y * 8, WHITE, TEXT_07);
	mlx_string_put(env->mlx, env->win, S_X, S_Y * 9, WHITE, TEXT_08);
	mlx_string_put(env->mlx, env->win, S_X, S_Y * 10, WHITE, TEXT_09);
	mlx_string_put(env->mlx, env->win, S_X, S_Y * 11, WHITE, TEXT_10);
	mlx_string_put(env->mlx, env->win, S_X, S_Y * 12, WHITE, TEXT_11);
	mlx_string_put(env->mlx, env->win, S_X, S_Y * 13, WHITE, TEXT_00);
}

static void	print_fract_and_inter(t_win *env, char *zoom_text)
{
	int	color[5];

	color[0] = (env->f->name[0] == 'm' ? RED : WHITE);
	color[1] = (env->f->name[0] == 'j' ? RED : WHITE);
	color[2] = (env->f->name[0] == 'b' ? RED : WHITE);
	color[3] = (env->f->name[0] == 's' ? RED : WHITE);
	color[4] = (env->f->name[0] == 'x' ? RED : WHITE);
	mlx_string_put(env->mlx, env->win, S_X + 5, S_Y * 14, WHITE, TEXT_12);
	mlx_string_put(env->mlx, env->win, S_X, S_Y * 15, color[0], TEXT_13);
	mlx_string_put(env->mlx, env->win, S_X, S_Y * 16, color[1], TEXT_14);
	mlx_string_put(env->mlx, env->win, S_X, S_Y * 17, color[2], TEXT_15);
	mlx_string_put(env->mlx, env->win, S_X, S_Y * 18, color[3], TEXT_16);
	mlx_string_put(env->mlx, env->win, S_X, S_Y * 19, color[4], TEXT_17);
	mlx_string_put(env->mlx, env->win, S_X, S_Y * 20, WHITE, TEXT_00);
	mlx_string_put(env->mlx, env->win, S_X, S_Y * 21, WHITE, zoom_text);
}

static void	put_help_tab(t_win *env, char *zoom)
{
	t_pic	pic;
	int		i;
	int		j;
	int		c;
	char	*zoom_text;

	zoom_text = ft_strjoin("max num of iteration is ", zoom);
	pic.img = mlx_new_image(env->mlx, SW_H, SH);
	pic.adr = mlx_get_data_addr(pic.img, &(pic.bpp), &(pic.sl), &(pic.e));
	c = NICE_BLUE;
	j = -1;
	while (++j < SH)
	{
		i = -1;
		while (++i < SW_H)
			ft_memcpy(&(pic.adr[i * 4 + pic.sl * j]), &c, 4);
	}
	mlx_put_image_to_window(env->mlx, env->win, pic.img, SW_F, 0);
	mlx_destroy_image(env->mlx, pic.img);
	print_key_controls(env);
	print_fract_and_inter(env, zoom_text);
	free(zoom);
	free(zoom_text);
}

static void	multitreading(t_win *env)
{
	pthread_t	t[8];

	pthread_create(&t[0], NULL, draw_one, env);
	pthread_create(&t[1], NULL, draw_two, env);
	pthread_create(&t[2], NULL, draw_three, env);
	pthread_create(&t[3], NULL, draw_four, env);
	pthread_create(&t[4], NULL, draw_five, env);
	pthread_create(&t[5], NULL, draw_six, env);
	pthread_create(&t[6], NULL, draw_seven, env);
	pthread_create(&t[7], NULL, draw_eight, env);
	pthread_join(t[0], NULL);
	pthread_join(t[1], NULL);
	pthread_join(t[2], NULL);
	pthread_join(t[3], NULL);
	pthread_join(t[4], NULL);
	pthread_join(t[5], NULL);
	pthread_join(t[6], NULL);
	pthread_join(t[7], NULL);
}

int			expose_hook(t_win *env)
{
	if (env != NULL)
	{
		put_help_tab(env, ft_itoa(env->f->max_iter));
		env->p->img = mlx_new_image(env->mlx, SW_F, SH);
		env->p->adr = mlx_get_data_addr(env->p->img, &(env->p->bpp),
			&(env->p->sl), &(env->p->e));
		multitreading(env);
		mlx_put_image_to_window(env->mlx, env->win, env->p->img, 0, 0);
		mlx_destroy_image(env->mlx, env->p->img);
		return (1);
	}
	else
		return (0);
}
