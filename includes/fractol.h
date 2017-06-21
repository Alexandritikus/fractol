/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:30:33 by oshudria          #+#    #+#             */
/*   Updated: 2017/06/20 22:24:29 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>

# ifdef __APPLE__
#  include "mac_keymap.h"
# elif __linux__
#  include "linux_keymap.h"
# endif

# define SW 1280
# define SH 720
# define SW_H 380
# define SW_F (SW - SW_H)
# define S_X (SW_F + 10)
# define S_Y 17

# define TEXT_00 "==================================="
# define TEXT_01 "KEY CONTROLS:"
# define TEXT_02 "ESC - quit"
# define TEXT_03 "< > ^ v - move"
# define TEXT_04 "+ - or mouse scroll - zoom"
# define TEXT_05 "PgUp PgDn - max iter change"
# define TEXT_06 "PAD_1 - PAD_5 - change fractal type"
# define TEXT_07 "Fn + (F1 - F9) - change julia mode"
# define TEXT_08 "I - interactive julia mode"
# define TEXT_09 "1 - 4 - switch color scheme"
# define TEXT_10 "Q A, W S, E D - change color coef"
# define TEXT_11 "works for 4th color mode"
# define TEXT_12 "FRACTAL LIST:"
# define TEXT_13 "1. Mandelbrot"
# define TEXT_14 "2. Julia"
# define TEXT_15 "3. Burning ship"
# define TEXT_16 "4. Spider"
# define TEXT_17 "5. Julia_X"

# define MNOTIFY 6
# define PMMASK (1L<<6)

# define RED_PRINT_ON "\e[38;5;196m"
# define RED_PRINT_OFF "\e[0m"

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0x990000
# define NICE_BLUE 0x4F4BF5

# define MAX_ITER 100
# define BASE_COLOR 0.015
# define COLOR_SENS 0.005

typedef struct		s_fract
{
	char			*name;
	double			rmin;
	double			rmax;
	double			imin;
	double			imax;
	double			cx;
	double			cy;
	double			x_zoom;
	double			y_zoom;
	double			x_shift;
	double			y_shift;
	int				max_iter;
}					t_fract;

typedef struct		s_pic
{
	void			*img;
	char			*adr;
	int				bpp;
	int				sl;
	int				e;
}					t_pic;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	struct s_fract	*f;
	struct s_pic	*p;
	int				color_scheme;
	double			r;
	double			g;
	double			b;
	int				motion_key;
	int				title;
}					t_win;
/*
** temp structures for expose function
*/
typedef struct		s_fract_param
{
	int				x;
	int				y;
	int				n;
	double			cx;
	double			cy;
	double			zx;
	double			zy;
	double			tz;
}					t_fract_param;

typedef struct		s_pixel
{
	int				x;
	int				y;
}					t_pixel;
/*
** check and get input param
*/
void				ft_print_usage();
void				ft_puterror(int param);
char				*fractal_name(char *name);
int					fractal_color(char *color_scheme);
/*
** initialize and update main structure
*/
t_win				*init_win(char *name, int color_scheme, void *mlx, int t);
t_pic				*init_pic();
t_fract				*init_fractal(char *fr_name);
void				update_zoom_shift(t_fract *fract);
void				ft_del_win(t_win **env);
/*
** chose fractal param
*/
double				get_fractal_size(char name, int size_type);
int					get_fractal(t_win *env, t_pixel start, t_pixel finish);
unsigned int		ft_getcolor(int k, t_win *env);
/*
** actions and rewriting the window
*/
int					expose_hook(t_win *env);
int					key_hook(int key, t_win *env);
int					mouse_hook(int key, int x, int y, t_win *env);
int					hook(int x, int y, t_win *env);
/*
** function which set part of main window
*/
void				*draw_one(void	*param);
void				*draw_two(void	*param);
void				*draw_three(void	*param);
void				*draw_four(void	*param);
void				*draw_five(void	*param);
void				*draw_six(void	*param);
void				*draw_seven(void	*param);
void				*draw_eight(void	*param);
/*
** fractal functions
*/
void				mandelbrot(t_win *env, t_pixel start, t_pixel finish);
void				julia(t_win *env, t_pixel start, t_pixel finish);
void				burning_ship(t_win *env, t_pixel start, t_pixel finish);
void				spider(t_win *env, t_pixel start, t_pixel finish);
void				julia_x(t_win *env, t_pixel start, t_pixel finish);
/*
** actions
*/
void				move(t_win *env, int key);
void				zoom_key(t_win *env, int key);
void				zoom_mouse(t_win *env, int key, int x, int y);
void				change_color_scheme(t_win *env, int key);
void				change_color_coef(t_win *env, int key);
void				reset_fractal(t_win *env);
int					switch_fractal(t_win *env, int key);

#endif
