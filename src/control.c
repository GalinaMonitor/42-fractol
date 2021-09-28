#include <fractol.h>
#include <control.h>

int	keyboard_hook(int keybord, t_vars *vars)
{
	if (keybord == KEY_ESC)
		close_window(vars);
	if (keybord == KEY_UP)
	{
		vars->fractol->move_ud -= MOVE_UD;
		vars->fractol_func(vars);
	}
	if (keybord == KEY_DOWN)
	{
		vars->fractol->move_ud += MOVE_UD;
		vars->fractol_func(vars);
	}
	if (keybord == KEY_RIGHT)
	{
		vars->fractol->move_rl -= MOVE_RL;
		vars->fractol_func(vars);
	}
	if (keybord == KEY_LEFT)
	{
		vars->fractol->move_rl += MOVE_RL;
		vars->fractol_func(vars);
	}
	if (keybord == KEY_Z)
	{
		vars->fractol->iter -= ITERATION_CHANGE_STEP;
		if (vars->fractol->iter < ITERATION_CHANGE_STEP)
			vars->fractol->iter = ITERATION_CHANGE_STEP;
		vars->fractol_func(vars);
	}
	if (keybord == KEY_X)
	{
		vars->fractol->iter += ITERATION_CHANGE_STEP;
		vars->fractol_func(vars);
	}
	if (keybord == KEY_C)
	{
		vars->fractol->color.red = rand() % COLOR_PARAM;
		vars->fractol->color.green = rand() % COLOR_PARAM;
		vars->fractol->color.blue = rand() % COLOR_PARAM;
		vars->fractol_func(vars);
	}
	if (keybord == KEY_MINUS)
	{
		default_settings(vars);
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
			vars->fractol->calibrate += CALIBRATION_CHANGE_STEP + (vars->fractol->calibrate / CALIBRATION_CHANGE_STEP);
			vars->fractol->move_rl += WINDOW_WIDTH/2 - (x + (vars->fractol->calibrate/ZOOM_PARAM));
			vars->fractol->move_ud -= (y + (vars->fractol->calibrate/ZOOM_PARAM))- WINDOW_HEIGHT/2;
		}
		else
		{
			vars->fractol->calibrate -= CALIBRATION_CHANGE_STEP + (vars->fractol->calibrate / CALIBRATION_CHANGE_STEP);
			vars->fractol->move_rl -= WINDOW_WIDTH/2 - (x + (vars->fractol->calibrate/ZOOM_PARAM));
			vars->fractol->move_ud += (y + (vars->fractol->calibrate/ZOOM_PARAM))- WINDOW_HEIGHT/2;
			if (vars->fractol->calibrate < CALIBRATION_CHANGE_STEP)
			{
				vars->fractol->calibrate = CALIBRATION_CHANGE_STEP;
				vars->fractol->move_rl = 0;
				vars->fractol->move_ud = 0;
			}
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

int	motion_hook(int x, int y, t_vars *vars)
{
	vars->fractol->mouse_rl = ((double)x - WINDOW_WIDTH / 2)/JULIA_PARAM;
	vars->fractol->mouse_ud = (WINDOW_HEIGHT / 2 - (double)y)/JULIA_PARAM;
	vars->fractol_func(vars);
	return 0;
}
