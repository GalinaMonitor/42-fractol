#include <fractol.h>
#include <control.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef union s_color
{
	int color;
	struct
	{
		uint8_t alpha: 8;
		uint8_t red: 8;
		uint8_t green: 8;
		uint8_t blue: 8;
	};
}	t_color;

typedef struct	s_vars {
	void	*mlx_ptr;
	void	*win_ptr;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return 0;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_window(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		write(1, "Exit\n", 5);
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit(0);
	}
	return 0;

}

int main(void)
{
	double x_coor = 1;
	double y_coor = 1;
	t_data img;
	t_vars vars;
	int color;

	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 500, 500, "mlx_test");
	img.img = mlx_new_image(vars.mlx_ptr, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);



	while (y_coor < 500)
	{
		color = ((int)x_coor * 255)/(int)y_coor+(((((int)y_coor - (int)x_coor) * 255)/(int)y_coor) << 16)+((((int)y_coor * 255)/(int)x_coor) << 8);
		if (y_coor > 100 && y_coor < 450)
		{
			x_coor = sqrt(20000 - (y_coor-250) * (y_coor-250)) - 250;
			my_mlx_pixel_put(&img, (int)x_coor, (int)y_coor, color);
			my_mlx_pixel_put(&img, 500 - (int)x_coor, (int)y_coor, color);
		}
		y_coor++;
	}
	x_coor = 1;
	y_coor = 1;
	while(x_coor++ < 500)
	{
		color = ((int)x_coor * 255)/(int)y_coor+(((((int)y_coor - (int)x_coor) * 255)/(int)y_coor) << 16)+((((int)y_coor * 255)/(int)x_coor) << 8);
		if (x_coor > 100 && x_coor < 400)
		{
			y_coor = sqrt(20000 - (x_coor-250) * (x_coor-250)) + 250;
			my_mlx_pixel_put(&img, (int)x_coor, (int)y_coor, color);
			my_mlx_pixel_put(&img, (int)x_coor , 500 - (int)y_coor, color);
		}
		x_coor++;
	}



	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, img.img, 0, 0);
	mlx_hook(vars.win_ptr, 2, 1L, close_window, &vars);
	mlx_loop(vars.mlx_ptr);
	return 0;
}


// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
//
// 	mlx_loop(vars.mlx);
// }
