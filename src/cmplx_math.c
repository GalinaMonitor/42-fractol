#include <fractol.h>
#include <control.h>

t_complex complex_square(t_complex num)
{
	t_complex result;
	result.re = num.re * num.re - num.im * num.im;
	result.im = 2 * num.re * num.im;
	return result;
}

double complex_module(t_complex num)
{
	double result;
	result = sqrt(num.re * num.re + num.im * num.im);
	return result;
}

t_complex complex_sum(t_complex num1, t_complex num2)
{
	t_complex result;
	result.re = num1.re + num2.re;
	result.im = num1.im + num2.im;
	return result;
}
