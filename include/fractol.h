#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../lib/libft/libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdint.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define THREAD_WIDTH ( WIN_WIDTH / THREADS )
# define THREADS 8
# define COLOR_MAIN 0x000000
# define ITER 50
# define MOVE_UD 50
# define MOVE_RL 50

# define ITER_CH 5
# define CALIB_CH 30
# define ZOOM_P 3
# define COLOR_P 20
# define JULIA_P 500

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
	int (*formula) (double, double, struct s_vars *);
}				t_vars;

t_complex	complex_sum(t_complex num1, t_complex num2);
double		complex_module(t_complex num);
t_complex	complex_square(t_complex num);
t_complex	complex_abs(t_complex num);

int			keyboard_hook(int keybord, t_vars *vars);
int			wheel_hook(int wheel, int x, int y, t_vars *vars);
int			close_window(t_vars *vars);
int			motion_hook(int x, int y, t_vars *vars);

int			draw_fractal(t_vars *vars);
void		draw_fractal_thread(t_vars *vars);

int			formula_julia(double a, double b, t_vars *vars);
int			formula_ship(double a, double b, t_vars *vars);
int			formula_mandel(double a, double b, t_vars *vars);

void		help();
void 		info(t_vars *vars);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

void		keyboard_hook_arrows(int key, t_vars *vars);
void		keyboard_hook_buttons(int key, t_vars *vars);
void		keyboard_hook_exit(int key, t_vars *vars);

void		default_settings(t_vars	*vars);
void		init_win_img(t_vars	*vars);

void		check_args(char **argv, t_vars *vars);
double		calc_a(double y, t_vars *vars);
double		calc_b(double y, t_vars *vars);
int			set_color(int iter, t_vars *vars);

#endif
