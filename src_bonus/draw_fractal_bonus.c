#include <fractol.h>
#include <control.h>

void	draw_fractal_thread(t_vars *vars)
{
	int		count_iter;
	double	x;
	double	y;
	int		iter;

	count_iter = vars->fractol->iter_pthread;
	vars->fractol->iter_pthread += 1;
	x = THREAD_WIDTH * count_iter;
	y = 0;
	while (x < THREAD_WIDTH * count_iter + THREAD_WIDTH)
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
}

int	draw_fractal(t_vars *vars)
{
	int	count;
	pthread_t tid[THREADS];

	count = 0;
	vars->fractol->iter_pthread = 0;
	while (count < THREADS)
	{
		pthread_create(&tid[count], NULL, (void *(*) (void *))draw_fractal_thread, vars);
		count++;
	}
	while (count >= 0)
	{
		count--;
		pthread_join(tid[count], NULL);
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img->img, 0, 0);
	info(vars);
	return 0;
}
