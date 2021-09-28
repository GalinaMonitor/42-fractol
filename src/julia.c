#include <fractol.h>
#include <control.h>

void	draw_julia_thread(t_vars *vars)
{
	int count_iter = vars->fractol->iter_pthread;
	vars->fractol->iter_pthread += 1;

	double x = THREAD_WIDTH * count_iter;
	double y = 0;
	double a = 0;
	double b = 0;
	int iter = vars->fractol->iter;

	int red = vars->fractol->color.red;
	int green = vars->fractol->color.green;
	int blue = vars->fractol->color.blue;

	t_complex num;
	t_complex zero;
	t_color color;
	int callibrate = vars->fractol->calibrate;
	while (x < THREAD_WIDTH * count_iter + THREAD_WIDTH)
	{
		while (y < WINDOW_HEIGHT)
		{
			b = (x - WINDOW_WIDTH/2 - vars->fractol->move_rl)/callibrate;
			a = (WINDOW_HEIGHT/2 - y + vars->fractol->move_ud)/callibrate;
			zero.im = a;
			zero.re = b;
			num.im = vars->fractol->mouse_ud;
			num.re = vars->fractol->mouse_rl;
			while (iter--)
			{
				zero = complex_square(zero);
				zero = complex_sum(zero, num);
				if (complex_module(zero) > 2)
					break;
			}
			if (iter <= 0)
				my_mlx_pixel_put(vars->img, x, y, COLOR_MAIN);
			else
			{
				color.red += (iter * red) % 255;
				color.green += (iter * green) % 255;
				color.blue += (iter * blue) % 255;
				my_mlx_pixel_put(vars->img, x, y, color.color);
				color.color = 0;
			}
			iter = vars->fractol->iter;
			y++;
		}
		y = 0;
		x++;
	}
}

int	draw_julia(t_vars *vars)
{
	int count = 0;

	vars->fractol->iter_pthread = 0;
	pthread_t tid[THREADS];
	while (count < THREADS)
	{
		pthread_create(&tid[count], NULL, (void *(*) (void *))draw_julia_thread, vars);
		count++;
	}
	while (count-- > 0)
		pthread_join(tid[count], NULL);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img->img, 0, 0);
	info(vars);
	return 0;
}
