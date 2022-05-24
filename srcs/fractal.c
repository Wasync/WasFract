#include "fractal.h"

EscapeData Mandelbrot(double x, double y, Fractal *data)
{
	Imaginary c;
	Imaginary z;
	Imaginary tmp;
	EscapeData esc;
	int i;
	double mod;

	c.r = MT_ScaleNumberf(x, (MT_Vector2){0, WIN_W}, (MT_Vector2){-2, 2});
	c.i = MT_ScaleNumberf(y, (MT_Vector2){0, WIN_H}, (MT_Vector2){-2, 2});
	z.r = c.r;
	z.i = c.i;
	i = 0;
	mod = 0;
	while (i < (LOD - 1) && (z.r * z.r + z.i * z.i) <= 4)
	{
		tmp.r = z.r;
		tmp.i = z.i;
		z.r = (tmp.r * tmp.r) - (tmp.i * tmp.i) + c.r;
		z.i = 2 * (tmp.r * tmp.i) + c.i;
		mod = sqrt(z.r * z.r + z.i * z.i);
		i++;
	}
	esc.iterations = i;
	esc.mod = i + 1 - (log (log(mod))) / log(2.0);
	return esc;
}

EscapeData Julia(double x, double y, Fractal *data)
{
	int i;
	double mod;
	Imaginary c;
	Imaginary z;
	Imaginary tmp;
	EscapeData esc;

	c.r = MT_ScaleNumberf(data->c.r, (MT_Vector2){0, WIN_W}, (MT_Vector2){-2, 2});
	c.i = MT_ScaleNumberf(data->c.i, (MT_Vector2){0, WIN_H}, (MT_Vector2){-2, 2});
	z.r = MT_ScaleNumberf(x, (MT_Vector2){0, WIN_W}, (MT_Vector2){-2, 2});
	z.i = MT_ScaleNumberf(y, (MT_Vector2){0, WIN_H}, (MT_Vector2){-2, 2});

	i = 0;
	while (i < LOD - 1 && (z.r * z.r + z.i * z.i) <= 4)
	{
		tmp.r = z.r;
		tmp.i = z.i;
		z.r = (tmp.r * tmp.r) - (tmp.i * tmp.i) + c.r;
		z.i = 2 * (tmp.r * tmp.i) + c.i;
		mod = sqrt(z.r * z.r + z.i * z.i);
		i++;
	}
	esc.iterations = i;
	esc.mod = i + 1 - (log (log(mod))) / log(2.0);
	return esc;
}

EscapeData Burningship(double x, double y, Fractal *data)
{
	Imaginary c;
	Imaginary z;
	Imaginary tmp;
	EscapeData esc;
	double mod;
	int i;

	c.r = MT_ScaleNumberf(x, (MT_Vector2){0, WIN_W}, (MT_Vector2){-2, 2});
	c.i = MT_ScaleNumberf(y, (MT_Vector2){0, WIN_H}, (MT_Vector2){-2, 2});
	z.r = c.r;
	z.i = c.i;

	i = 0;
	while (i < LOD - 1 && (z.r * z.r + z.i * z.i) <= 4)
	{
		tmp.r = z.r;
		tmp.i = z.i;
		z.r = fabs((tmp.r * tmp.r) - (tmp.i * tmp.i) + c.r);
		z.i = fabs(2 * (tmp.r * tmp.i) + c.i);
		mod = sqrt(z.r * z.r + z.i * z.i);
		i++;
	}
	esc.iterations = i;
	esc.mod = i + 1 - (log (log(mod))) / log(2.0);
	return esc;
}

EscapeData Owo(double x, double y, Fractal *data)
{
	Imaginary c;
	Imaginary z;
	Imaginary tmp;
	EscapeData esc;
	double mod;
	int i;

	c.r = MT_ScaleNumberf(data->c.r, (MT_Vector2){0, WIN_W}, (MT_Vector2){-2, 2});
	c.i = MT_ScaleNumberf(data->c.i, (MT_Vector2){0, WIN_H}, (MT_Vector2){-2, 2});
	z.r = MT_ScaleNumberf(x, (MT_Vector2){0, WIN_W}, (MT_Vector2){-2, 2});
	z.i = MT_ScaleNumberf(y, (MT_Vector2){0, WIN_H}, (MT_Vector2){-2, 2});
	i = 0;
	while (i < LOD - 1 && (z.r * z.r + z.i * z.i) < 2)
	{
		tmp.r = z.r;
		tmp.i = z.i;
		z.r = (tmp.r * tmp.r - tmp.i * tmp.i + c.r * 1.5) / 2;
		z.i = 2 * (tmp.r * tmp.i) + c.i;
		mod = sqrt(z.r * z.r + z.i * z.i);
		i++;
	}
	esc.iterations = i;
	esc.mod = i + 1 - (log (log(mod))) / log(2.0);
	return esc;
}