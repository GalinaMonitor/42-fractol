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
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 575, 20, 0xFFFFFF, "------ZOOM MOUSEWHEEL------");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 575, 40, 0xFFFFFF, "--MOVE UP/DOWN RIGHT/LEFT--");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 575, 60, 0xFFFFFF, "----------COLOR  C---------");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 575, 80, 0xFFFFFF, "------DEFAULT MINUSKEY-----");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 575, 100, 0xFFFFFF, "-------ITERATIONS Z/X------");
}
