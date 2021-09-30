#include <fractol.h>
#include <control.h>

void	keyboard_hook_arrows(int key, t_vars *vars)
{
	if (key == KEY_UP)
	{
		vars->fractol->move_ud -= MOVE_UD;
		draw_fractal(vars);
	}
	else if (key == KEY_DOWN)
	{
		vars->fractol->move_ud += MOVE_UD;
		draw_fractal(vars);
	}
	else if (key == KEY_RIGHT)
	{
		vars->fractol->move_rl -= MOVE_RL;
		draw_fractal(vars);
	}
	else if (key == KEY_LEFT)
	{
		vars->fractol->move_rl += MOVE_RL;
		draw_fractal(vars);
	}
}

void	keyboard_hook_buttons(int key, t_vars *vars)
{
	if (key == KEY_Z)
	{
		vars->fractol->iter -= ITER_CH;
		if (vars->fractol->iter < ITER_CH)
			vars->fractol->iter = ITER_CH;
		draw_fractal(vars);
	}
	else if (key == KEY_X)
	{
		vars->fractol->iter += ITER_CH;
		draw_fractal(vars);
	}
	else if (key == KEY_C)
	{
		vars->fractol->color.red = rand() % COLOR_P;
		vars->fractol->color.green = rand() % COLOR_P;
		vars->fractol->color.blue = rand() % COLOR_P;
		draw_fractal(vars);
	}
	else if (key == KEY_MINUS)
	{
		default_settings(vars);
		draw_fractal(vars);
	}
}

void	keyboard_hook_exit(int key, t_vars *vars)
{
	if (key == KEY_ESC)
		close_window(vars);
}
