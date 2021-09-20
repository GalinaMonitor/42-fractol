#include <fractol.h>
#include <control.h>



int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return 0;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_window(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		write(1, "Exit\n", 5);
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit(0);
	}
	return 0;
}

int	draw_mandelbrot(int keycode, t_vars *vars)
{
	double x = 0;
	double y = 0;
	double a = 0;
	double b = 0;
	int iter = 50;
	t_complex num;
	t_complex zero;
	int color;
	int callibrate = 100;
	if (keycode == KEY_UP)
	{
		while (x < 500)
		{
			while (y < 500)
			{
				b = (x - 500/2)/callibrate;
				a = (500/2 - y)/callibrate;
				zero.im = 0;
				zero.re = 0;
				num.re = b;
				num.im = a;
				while (iter--)
				{
					zero = complex_square(zero);
					zero = complex_sum(zero, num);
					if (complex_module(zero) > 2)
						break;
				}
				if (iter <= 0)
					my_mlx_pixel_put(vars->img, x, y, 0x00FF00);
				else
					my_mlx_pixel_put(vars->img, x, y, 0xFFFFFF);
				iter = 50;
				y++;
			}
			y = 0;
			x++;
		}
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img->img, 0, 0);
	}
	return 0;
}

int main(void)
{
	double x = 0;
	double y = 0;
	double a = 0;
	double b = 0;
	int iter = 50;
	t_complex num;
	t_complex zero;
	t_data img;
	t_vars vars;
	int color;
	int callibrate = 10;

	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 500, 500, "mlx_test");
	img.img = mlx_new_image(vars.mlx_ptr, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	vars.img = &img;

	mlx_hook(vars.win_ptr, 2, 1L, draw_mandelbrot, &vars);
	mlx_loop(vars.mlx_ptr);
	return 0;
}
