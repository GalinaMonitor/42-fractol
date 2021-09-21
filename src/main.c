#include <fractol.h>
#include <control.h>

int main(int argc, char **argv)
{
	t_data img;
	t_vars vars;
	t_fractol fractol;
	int color;
	// if (ft_strncmp(argv[1], "julia", 20) == 0)
		// vars.fractol_func = draw_julia;
	// if (ft_strncmp(argv[1], "mandelbrot", 20) == 0)
		// vars.fractol_func = draw_mandelbrot;

	fractol.calibrate = 100;
	fractol.color.color = 0;
	fractol.move_rl = 0;
	fractol.move_ud = 0;
	vars.fractol = &fractol;
	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 800, 800, "mlx_test");
	img.img = mlx_new_image(vars.mlx_ptr, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	vars.img = &img;

	mlx_hook(vars.win_ptr, WHEEL, MASK_WHEEL, wheel_hook, &vars);
	mlx_hook(vars.win_ptr, KEY_PRESS, MASK_KEY_PRESS, keyboard_hook, &vars);
	mlx_loop(vars.mlx_ptr);
	return 0;
}
