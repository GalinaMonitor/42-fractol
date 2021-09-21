#include <fractol.h>
#include <control.h>

int	draw_julia(t_vars *vars)
{
	double x = 0;
	double y = 0;
	double a = 0;
	double b = 0;
	int iter = 50;

	int red = vars->fractol->color.red;
	int green = vars->fractol->color.green;
	int blue = vars->fractol->color.blue;

	t_complex num;
	t_complex zero;
	t_color color;
	int callibrate = vars->fractol->calibrate;

	while (x < 800)
	{
		while (y < 800)
		{
			b = (x - 800/2 - vars->fractol->move_rl)/callibrate;
			a = (800/2 - y + vars->fractol->move_ud)/callibrate;
			zero.im = a;
			zero.re = b;
			num.im = -0.2;
			num.re = 0.176;
			while (iter--)
			{
				zero = complex_square(zero);
				zero = complex_sum(zero, num);
				if (complex_module(zero) > 2)
					break;
			}
			if (iter <= 0)
				my_mlx_pixel_put(vars->img, x, y, 0xFFFFFF);
			else
			{
				color.red += (iter * red) % 255;
				color.green += (iter * green) % 255;
				color.blue += (iter * blue) % 255;
				my_mlx_pixel_put(vars->img, x, y, color.color);
				color.color = 0;
			}
			iter = 50;
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img->img, 0, 0);
	info(vars);
	return 0;
}
