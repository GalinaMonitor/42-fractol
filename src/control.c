#include <fractol.h>
#include <control.h>

int	keyboard_hook(int key, t_vars *vars)
{
	if (key == KEY_Z || key == KEY_X || key == KEY_C || key == KEY_MINUS)
		keyboard_hook_buttons(key, vars);
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_RIGHT || key == KEY_LEFT)
		keyboard_hook_arrows(key, vars);
	if (key == KEY_ESC)
		keyboard_hook_exit(key, vars);
	return 0;
}

int	wheel_hook(int wheel, int x, int y, t_vars *vars)
{
	if (wheel == SCROLL_UP || wheel == SCROLL_DOWN)
	{
		if (wheel == SCROLL_DOWN)
		{
			vars->fractol->move_rl += (WIN_HEIGHT/2 - x)/ZOOM_P;
			vars->fractol->move_ud -= (y - WIN_WIDTH/2)/ZOOM_P;
			vars->fractol->calibrate += CALIB_CH;
		}
		else
		{
			vars->fractol->move_rl *= 9;
			vars->fractol->move_ud *= 9;
			vars->fractol->move_rl /= 10;
			vars->fractol->move_ud /= 10;
			vars->fractol->calibrate -= CALIB_CH * 3;
			if (vars->fractol->calibrate < CALIB_CH)
			{
				vars->fractol->calibrate = CALIB_CH;
				vars->fractol->move_rl = 0;
				vars->fractol->move_ud = 0;
			}
		}
		draw_fractal(vars);
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

int	motion_hook(int x, int y, t_vars *vars)
{
	vars->fractol->mouse_rl = ((double)x - WIN_WIDTH / 2)/JULIA_P;
	vars->fractol->mouse_ud = (WIN_HEIGHT / 2 - (double)y)/JULIA_P;
	draw_fractal(vars);
	return 0;
}
