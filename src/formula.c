#include <fractol.h>
#include <control.h>

int		formula_julia(double a, double b, t_vars *vars)
{
	t_complex num;
	t_complex zero;
	int iter;

	iter = vars->fractol->iter;
	zero.im = a;
	zero.re = b;
	num.im = vars->fractol->mouse_ud;
	num.re = vars->fractol->mouse_rl;
	while (iter--)
	{
		zero = complex_square(zero);
		zero = complex_sum(zero, num);
		if (complex_module(zero) > 2)
			return (iter);
	}
	return 0;
}

int		formula_ship(double a, double b, t_vars *vars)
{
	t_complex num;
	t_complex zero;
	int iter;

	iter = vars->fractol->iter;
	zero.im = 0;
	zero.re = 0;
	num.re = b;
	num.im = -a;
	while (iter--)
	{
		zero = complex_abs(zero);
		zero = complex_square(zero);
		zero = complex_sum(zero, num);
		if (complex_module(zero) > 2)
			return (iter);
	}
	return 0;
}

int		formula_mandel(double a, double b, t_vars *vars)
{
	t_complex num;
	t_complex zero;
	int iter;

	iter = vars->fractol->iter;
	zero.im = 0;
	zero.re = 0;
	num.re = b;
	num.im = -a;
	while (iter--)
	{
		zero = complex_square(zero);
		zero = complex_sum(zero, num);
		if (complex_module(zero) > 2)
			return (iter);
	}
	return 0;
}

