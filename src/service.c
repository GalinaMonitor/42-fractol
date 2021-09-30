#include <fractol.h>
#include <control.h>

void	check_args(char **argv, t_vars *vars)
{
	if (ft_strncmp(argv[1], "julia", 20) == 0)
		vars->formula = formula_julia;
	else if (ft_strncmp(argv[1], "mandelbrot", 20) == 0)
		vars->formula = formula_mandel;
	else if (ft_strncmp(argv[1], "ship", 20) == 0)
		vars->formula = formula_ship;
	else
		help();
}

double	calc_a(double y, t_vars *vars)
{
	return ((y + vars->fractol->move_ud)/vars->fractol->calibrate);
}

double	calc_b(double x, t_vars *vars)
{
	return ((x - vars->fractol->move_rl)/vars->fractol->calibrate);
}

int	set_color(int iter, t_vars *vars)
{
	t_color color;

	color.color = 0;
	color.red = (iter * vars->fractol->color.red) % 255;
	color.green = (iter * vars->fractol->color.green) % 255;
	color.blue = (iter * vars->fractol->color.blue) % 255;
	return (color.color);
}
