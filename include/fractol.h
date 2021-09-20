#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
		uint8_t alpha: 8;
		uint8_t red: 8;
		uint8_t green: 8;
		uint8_t blue: 8;
	};
}	t_color;

typedef struct complex
{
	double re;
	double im;
} 				t_complex;

typedef struct	s_vars {
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*img;
}				t_vars;

t_complex complex_sum(t_complex num1, t_complex num2);
double complex_module(t_complex num);
t_complex complex_square(t_complex num);

#endif
