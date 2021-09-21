#include <fractol.h>
#include <control.h>

int	keyboard_hook(int keybord, t_vars *vars)
{
	if (keybord == KEY_ESC)
		close_window(vars);
	if (keybord == KEY_UP)
	{
		vars->fractol->move_ud -= 50;
		vars->fractol_func(vars);
	}
	if (keybord == KEY_DOWN)
	{
		vars->fractol->move_ud += 50;
		vars->fractol_func(vars);
	}
	if (keybord == KEY_RIGHT)
	{
		vars->fractol->move_rl -= 50;
		vars->fractol_func(vars);
	}
	if (keybord == KEY_LEFT)
	{
		vars->fractol->move_rl += 50;
		vars->fractol_func(vars);
	}

	if (keybord == KEY_C)
	{
		vars->fractol->color.red = rand() % 20;
		vars->fractol->color.green = rand() % 20;
		vars->fractol->color.blue = rand() % 20;
		vars->fractol_func(vars);
	}
	if (keybord == KEY_MINUS)
	{
		vars->fractol->calibrate = 100;
		vars->fractol->move_rl = 0;
		vars->fractol->move_ud = 0;
		vars->fractol_func(vars);
	}
	return 0;
}

int	wheel_hook(int wheel, int x, int y, t_vars *vars)
{
	if (wheel == SCROLL_UP || wheel == SCROLL_DOWN)
	{
		if (wheel == SCROLL_DOWN)
		{
			vars->fractol->calibrate += 30;
			vars->fractol->move_rl += (400 - x)/10;
			vars->fractol->move_ud -= (y - 400)/10;
		}
		else
		{
			vars->fractol->calibrate -= 30;
			vars->fractol->move_rl += (400 - x)/10;
			vars->fractol->move_ud -= (y - 400)/10;
			if (vars->fractol->calibrate < 0)
				vars->fractol->calibrate = 1;
		}

		vars->fractol_func(vars);
	}
	return 0;
}

int	close_window(t_vars *vars)
{
	write(1, "Exit\n", 5);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	exit(0);
	return 0;
}
