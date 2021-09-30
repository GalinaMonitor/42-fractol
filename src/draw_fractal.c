#include <fractol.h>
#include <control.h>

int	draw_fractal(t_vars *vars)
{
	double x;
	double y;
	int iter;

	x = 0;
	y = 0;
	while (x < WIN_WIDTH)
	{
		while (y < WIN_HEIGHT)
		{
			iter = vars->formula(calc_a(WIN_HEIGHT/2 - y, vars),\
								calc_b(x - WIN_WIDTH/2, vars), vars);
			if (iter <= 0)
				my_mlx_pixel_put(vars->img, x, y, COLOR_MAIN);
			else
				my_mlx_pixel_put(vars->img, x, y, set_color(iter, vars));
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img->img, 0, 0);
	info(vars);
	return 0;
}
