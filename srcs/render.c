#include "fractal.h"

typedef EscapeData (*Frac_func)(double x, double y, Fractal *frac);

static void SinColoring(Fractal *data, EscapeData esc, Uint8 *r, Uint8 *g, Uint8 *b)
{
	SinWave sr;
	SinWave sg;
	SinWave sb;

	sr = data->colorData.waveData[0];
	sg = data->colorData.waveData[1];
	sb = data->colorData.waveData[2];
	*r = sin(sr.frequency * esc.mod + sr.add) * sr.mid + (255 - sr.mid);
	*g = sin(sg.frequency * esc.mod + sg.add) * sg.mid + (255 - sg.mid);
	*b = sin(sb.frequency * esc.mod + sb.add) * sb.mid + (255 - sb.mid);
}

static void GradColoring(Fractal *data, EscapeData esc, Uint8 *r, Uint8 *g, Uint8 *b)
{
	int color;

	color = data->colorData.colors[data->colorData.index][esc.iterations];
	*r = color >> 24;
	*g = color >> 16;
	*b = color >> 8;	
}

void RenderToScreen(Fractal *data)
{
	static Frac_func fractals[4];
	int x;
	int y;
	int color;
	Uint8 r;
	Uint8 g;
	Uint8 b;
	double pixelX;
	double pixelY;
	EscapeData esc;

	SDLX_Display *display;

	display = SDLX_DisplayGet();
	fractals[0] = Mandelbrot;
	fractals[1] = Julia;
	fractals[2] = Burningship;
	fractals[3] = Owo;

	y = 0;
	if (data->paused != 0)
	{
		data->c.r = data->mouse_x;
		data->c.i = data->mouse_y;
	}
	pixelY = data->cam.position.y - ((WIN_H / data->cam.scale) * 0.5);
	while (y < WIN_H)
	{
		x  = 0;
		pixelX = data->cam.position.x - ((WIN_W / data->cam.scale) * 0.5);
		while (x < WIN_W)
		{
			esc = fractals[data->fractal](pixelX, pixelY, data);
			if (data->colorData.mode == 1)
				SinColoring(data, esc, &r, &g, &b);
			else 
				GradColoring(data, esc, &r, &g, &b);
			SDL_SetRenderDrawColor(display->renderer, r, g, b, 255);
			SDL_RenderDrawPoint(display->renderer,  x, y);
			x++;
			pixelX += (WIN_W / data->cam.scale) / WIN_W;
		}
		pixelY += (WIN_H / data->cam.scale ) / WIN_H;
		y++;
	}
}