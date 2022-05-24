#ifndef FRACTAL_H
# define FRACTAL_H

# include "SDLX/SDLX.h"
# include "MT/MT.h"
# include "Gradient/gradient.h"

# define LOD 150

typedef struct Imaginary
{
	double r;
	double i;
} Imaginary;

typedef struct SinWave
{
	double frequency;
	double add;
	double mid;
}				SinWave;

typedef struct Color_data
{
	int rgb;
	int mode;
	int index;
	int ncolors;
	Uint32 **colors;
	SinWave waveData[3];
}				Color_data;

typedef struct Camera
{
	MT_Vector2 position;
	double scale;
}				Camera;

typedef struct EscapeData
{
	int iterations;
	double mod;
}				EscapeData;

typedef struct Fractal
{
	int paused;
	int fractal;
	int nfractal;
	double zoom_step;

	int mouse_x;
	int mouse_y;

	Imaginary c;
	Color_data colorData;
	Camera cam;
} Fractal;

EscapeData Mandelbrot(double x, double y, Fractal *data);
EscapeData Julia(double x, double y, Fractal *data);
EscapeData Burningship(double x, double y, Fractal *data);
EscapeData Owo(double x, double y, Fractal *data);

void RenderToScreen(Fractal *data);
void InputParse(Fractal *data);
Uint32 **init_colors();

#endif