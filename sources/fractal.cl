#define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

int		ft_color(int n, int itermax);
int		ft_color(int n, int itermax)
{
	float pct;

	pct = (float)n / (float)itermax;
	if (pct == 1.0)
		return (0xFFFFFF);
	return ((RGB(100, pct * 255, 100)));
}

double	ft_abs_double(double nb);
double	ft_abs_double(double nb)
{
	if (nb >= 0)
		return (nb);
	return (-nb);
}

int	ft_get_color(int start, int end, double percent);
int	ft_get_color(int start, int end, double percent)
{
   return ((int)((1 - percent) * start + percent * end));
}

int ft_red_color(int n, int itermax);
int ft_red_color(int n, int itermax)
{
	double percent;
	int red;
	int green;
	int blue;

	if (n < itermax / 3)
    {
        percent = n / (double)(itermax / 3);
        red = ft_get_color(0, 0xFF, percent);
        green = ft_get_color(0, 0, percent);
        blue = ft_get_color(0, 0, percent);
    }
    else if (n > (itermax * 2 / 3))
    {
        percent = (n * 2 / 3) / (double)(itermax * 2 / 3);
        red = ft_get_color(0xFF, 0xFF, percent);
        green = ft_get_color(0xFF, 0xFF, percent);
        blue = ft_get_color(0xFF, 0, percent);
    }
    else
    {
        percent = n / (double)(itermax / 3);
        red = ft_get_color(0xFF, 0xFF, percent);
        green = ft_get_color(0, 0xFF, percent);
        blue = ft_get_color(0, 0, percent);
    }
	return ((red << 16) | (green << 8) | blue);
}

__kernel void fractal(
    __global int *output,
    int width,
    int height,
    int fractal,
    int max_iter,
    double Min_Re,
    double Max_Re,
    double Min_Im,
    double Max_Im,
    double step_x,
    double step_y,
    double Re_Julia_const,
    double Im_Julia_const,
    int color)
{
    int id;
    int x;
    int y;
    double c_r;
    double c_i;
    double z_r;
    double z_i;
    double tmp;
    int n;

    id = get_global_id(0);
    if (id < 0 || id >= width * height)
        return ;
    
    x = id % width;
    y = id / width;

    if (fractal == 1)
    {
        c_i = Min_Im + y * step_y;
        c_r = Min_Re + x * step_x;
        z_r = 0;
        z_i = 0;
        n = 0;
        while (z_r * z_r + z_i * z_i < 4.0 && n < max_iter)
        {
            tmp = z_r;
            z_r = z_r * z_r - z_i * z_i + c_r;
            z_i = 2.0 * z_i * tmp + c_i;
            n++;
        }
    }
    else if (fractal == 2)
    {
        c_i = Im_Julia_const;
        c_r = Re_Julia_const;
        z_r = Min_Re + x * step_x;
        z_i = Min_Im + y * step_y;
        n = 0;
        while (z_r * z_r + z_i * z_i < 4.0 && n < max_iter)
        {
            tmp = z_r;
            z_r = z_r * z_r - z_i * z_i + c_r;
            z_i = 2.0 * z_i * tmp + c_i;
            n++;
        }
    }
    else if (fractal == 3)
    {
        c_i = Min_Im + y * step_y;
        c_r = Min_Re + x * step_x;
        z_r = 0;
        z_i = 0;
        n = 0;
        while (z_r * z_r + z_i * z_i < 4.0 && n < max_iter)
        {
            tmp = z_r;
            z_r = z_r * z_r - z_i * z_i + c_r;
            z_i = fabs(2.0 * z_i * tmp) + c_i;
            n++;
        }
    }
    if (color == 0)
	{
		if (n == max_iter)
			output[id] = 0;
		else
			output[id] = 0xFFFFFF;
	}
	else if (color == 1)
		output[id] = ft_color(n, max_iter);
	else if (color == 2)
	{
		if (n == max_iter)
			output[id] = 0;
		else
			output[id] = 0x00000F << n;
	}
	else if (color == 3)
		output[id] = ft_red_color(n, max_iter);
}