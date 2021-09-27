#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../lib/libft/libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <pthread.h>

# include <stdint.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef union s_color
{
	int color;
	struct
	{
		uint8_t green: 8;
		uint8_t red: 8;
		uint8_t blue: 8;
		uint8_t alpha: 8;
	};
}	t_color;

typedef struct s_complex
{
	double re;
	double im;
} 				t_complex;

typedef struct s_fractol
{
	int calibrate;
	int move_rl;
	int move_ud;
	double mouse_rl;
	double mouse_ud;
	int iter;
	int iter_pthread;
	t_color color;
}	t_fractol;

typedef struct	s_vars
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		*img;
	t_fractol	*fractol;
	int (*fractol_func) (struct s_vars *);
}				t_vars;

t_complex complex_sum(t_complex num1, t_complex num2);
double complex_module(t_complex num);
t_complex complex_square(t_complex num);
t_complex complex_abs(t_complex num);

int		wheel_hook(int keybord, int x, int y, t_vars *vars);
int		keyboard_hook(int keybord, t_vars *vars);
int		wheel_hook(int wheel, int x, int y, t_vars *vars);
int		close_window(t_vars *vars);
void 	info(t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		draw_ship(t_vars *vars);
int		draw_julia(t_vars *vars);
int		draw_mandelbrot(t_vars *vars);
int		motion_hook(int x, int y, t_vars *vars);
void	draw_mandelbrot_thread(t_vars *vars);
void	draw_julia_thread(t_vars *vars);
void	draw_ship_thread(t_vars *vars);
void	init_win_img(t_vars	*vars);
void	default_settings(t_vars	*vars);

#endif
