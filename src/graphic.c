#include <fractol.h>
#include <control.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void info(t_vars *vars)
{
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 0, 20, 0xFFFFFF, "ITERATIONS =");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 125, 20, 0xFFFFFF, \
												ft_itoa(vars->fractol->iter));
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 0, 40, 0xFFFFFF, "MOVE_RL    =");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 125, 40, 0xFFFFFF, \
												ft_itoa(vars->fractol->move_rl));
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 0, 60, 0xFFFFFF, "MOVE_UD    =");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 125, 60, 0xFFFFFF, \
												ft_itoa(vars->fractol->move_ud));
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 0, 80, 0xFFFFFF, "CALIBRATE  =");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 125, 80, 0xFFFFFF, \
												ft_itoa(vars->fractol->calibrate));

	mlx_string_put(vars->mlx_ptr, vars->win_ptr, WIN_WIDTH - 225, 20, 0xFFFFFF,\
													"------ZOOM MOUSEWHEEL------");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, WIN_WIDTH - 225, 40, 0xFFFFFF, \
													"--MOVE UP/DOWN RIGHT/LEFT--");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, WIN_WIDTH - 225, 60, 0xFFFFFF, \
													"----------COLOR  C---------");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, WIN_WIDTH - 225, 80, 0xFFFFFF, \
													"------DEFAULT MINUSKEY-----");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, WIN_WIDTH - 225, 100, 0xFFFFFF, \
													"-------ITERATIONS Z/X------");
}

void help()
{
	write(1, " ____________________________________________________ \n", 55);
	write(1, "|                      Fract'ol                      |\n", 55);
	write(1, "|____________________________________________________|\n", 55);
	write(1, "|                      mandelbrot                    |\n", 55);
	write(1, "|                      julia                         |\n", 55);
	write(1, "|                      ship                          |\n", 55);
	write(1, "|____________________________________________________|\n", 55);
	exit(0);
}
