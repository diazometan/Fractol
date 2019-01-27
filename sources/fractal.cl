#define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

int		color(int n, int itermax);
int		color(int n, int itermax)
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
   /* if (n == max_iter)
		output[id] = 0;
	else
		output[id] = 0x00000F << n;*/
   output[id] = color(n, max_iter);
}