#include <fractol.h>
#include <control.h>

void	init_win_img(t_vars	*vars)
{
	vars->mlx_ptr = mlx_init();
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, 800, 800, "mlx_test");
	vars->img->img = mlx_new_image(vars->mlx_ptr, 800, 800);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel, &vars->img->line_length, &vars->img->endian);
}

void	default_settings(t_vars	*vars)
{
	vars->fractol->calibrate = 100;
	vars->fractol->iter = 20;
	vars->fractol->color.color = 0;
	vars->fractol->move_rl = 0;
	vars->fractol->move_ud = 0;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Available fractals:\n-mandelbrot\n-julia\n-ship\nTo start: ./fractal <name>\n", 72);
		return(0);
	}
	t_data img;
	t_vars vars;
	t_fractol fractol;
	vars.fractol = &fractol;
	vars.img = &img;

	init_win_img(&vars);
	default_settings(&vars);

	if (ft_strncmp(argv[1], "julia", 20) == 0)
		vars.fractol_func = draw_julia;
	if (ft_strncmp(argv[1], "mandelbrot", 20) == 0)
		vars.fractol_func = draw_mandelbrot;
	if (ft_strncmp(argv[1], "ship", 20) == 0)
		vars.fractol_func = draw_ship;

	mlx_hook(vars.win_ptr, WHEEL, MASK_WHEEL, wheel_hook, &vars);
	mlx_hook(vars.win_ptr, KEY_PRESS, MASK_KEY_PRESS, keyboard_hook, &vars);
	if (ft_strncmp(argv[1], "julia", 20) == 0)
		mlx_hook(vars.win_ptr, MOTION_NOTIFY, MASK_POINTER_MOTION, motion_hook, &vars);
	mlx_loop(vars.mlx_ptr);
	return 0;
}
