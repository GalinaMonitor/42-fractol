#include <fractol.h>
#include <control.h>

void	init_win_img(t_vars	*vars)
{
	vars->mlx_ptr = mlx_init();
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "mlx_test");
	vars->img->img = mlx_new_image(vars->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel, &vars->img->line_length, &vars->img->endian);
}

void	default_settings(t_vars	*vars)
{
	vars->fractol->calibrate = CALIB_CH * 5;
	vars->fractol->iter = ITER;
	vars->fractol->color.color = COLOR_P;
	vars->fractol->move_rl = 0;
	vars->fractol->move_ud = 0;
}

int main(int argc, char **argv)
{
	t_data img;
	t_vars vars;
	t_fractol fractol;

	if (argc != 2)
		help();
	vars.fractol = &fractol;
	vars.img = &img;
	check_args(argv, &vars);
	init_win_img(&vars);
	default_settings(&vars);

	mlx_hook(vars.win_ptr, WHEEL, MASK_WHEEL, wheel_hook, &vars);
	mlx_hook(vars.win_ptr, KEY_PRESS, MASK_KEY_PRESS, keyboard_hook, &vars);
	if (ft_strncmp(argv[1], "julia", 20) == 0)
		mlx_hook(vars.win_ptr, MOTION_NOTIFY, MASK_POINTER_MOTION, motion_hook, &vars);
	draw_fractal(&vars);
	mlx_loop(vars.mlx_ptr);
	return 0;
}
