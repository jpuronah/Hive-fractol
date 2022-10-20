
void	julia_calculus(t_mlx mlx)//, float a, float b)
{
	//mlx.constant_y_julia = a;
	//mlx.constant_x_julia = b;
	printf("julia_calculus; %f, %f\n", mlx.constant_x_julia, mlx.constant_y_julia);
	clear_image(mlx.image);
	mlx.y = 0;
	mlx.x = 0;
	while (mlx.y < WIN_HEIGHT)
	{
		mlx.x = 0;
		mlx.constant_y = mlx.y_axis_min + mlx.y * mlx.pixel_length_y;
		while (mlx.x < WIN_WIDTH)
		{
			mlx.constant_x = mlx.x_axis_min + mlx.x * mlx.pixel_length_x;
			mlx.z_real = mlx.constant_x;
			mlx.z_imaginary = mlx.constant_y;
			mlx.color = 0;
			run_fractal_equation_julia(&*mlx);
			color_pixel_in_image(mlx.image, mlx.x, mlx.y, set_colour_julia(mlx.color));
			mlx.x++;
		}
		mlx.y++;
	}
	mlx_put_image_to_window(mlx.mlxptr, mlx.winptr, mlx.image->image, 0, 0);
	menu(mlx);
}
int	mouse_events_julia(int x, int y, t_mlx *mlx)
{
	mlx->constant_x_julia = 0.0;
	printf("zooms juliamouse; %f, %f\n", mlx->pixel_length_x, mlx->pixel_length_y);
	mlx->constant_y_julia = 0.0;
	if ((x > 0 && x < WIN_WIDTH) && (y > 0 && y < WIN_HEIGHT))
	{
		mlx->constant_y_julia = (y - WIN_HEIGHT * 0.5) / (WIN_HEIGHT * 0.5f);
		mlx->constant_x_julia = (x - WIN_WIDTH * 0.5) / (WIN_WIDTH * 0.5f);
	}
	printf("mouse_events_julia; %d, %d\n", x, y);
	printf("mouse_events_julia; %f, %f\n", mlx->constant_x_julia, mlx->constant_y_julia);
	julia_calculus(*mlx);//, mlx->constant_y_julia, mlx->constant_x_julia);
	return (0);
}
