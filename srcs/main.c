#include "fractal.h"
#include <emscripten.h>

Fractal *data;
SDLX_Display *display;

Fractal *Fractal_Init()
{
	Fractal *data;
	
	data = calloc(1, sizeof(*data));
	data->colorData.colors = init_colors();
	data->colorData.index = 0;
	data->colorData.ncolors = 7;
	data->cam.scale = 1;
	data->zoom_step = 0.5;
	data->cam.position.x = WIN_H / 2;
	data->cam.position.y = WIN_W / 2;
	data->nfractal = 4;
	data->fractal = 0;
	data->paused = 1;

	data->colorData.waveData[0].frequency = 0.33;
	data->colorData.waveData[0].add = 1;
	data->colorData.waveData[0].mid = 230;

	data->colorData.waveData[1].frequency = 0.33;
	data->colorData.waveData[1].add = 1;
	data->colorData.waveData[1].mid = 230;

	data->colorData.waveData[2].frequency = 0.33;
	data->colorData.waveData[2].add = 1;
	data->colorData.waveData[2].mid = 230;

	
	SDLX_InputMap(SDL_SCANCODE_W, 1, SDLX_UP, 0);
	SDLX_InputMap(SDL_SCANCODE_A, 1, SDLX_LEFT, 0);
	SDLX_InputMap(SDL_SCANCODE_S, 1, SDLX_DOWN, 0);
	SDLX_InputMap(SDL_SCANCODE_D, 1, SDLX_RIGHT, 0);

	return data;
}

void main_loop()
{
	SDL_RenderClear(display->renderer);
	InputParse(data);
	RenderToScreen(data);
	SDL_RenderPresent(display->renderer);
}

int main(void)
{
	SDLX_DisplaySet();
	display = SDLX_DisplayGet();
	data = Fractal_Init();

	emscripten_set_main_loop(main_loop, 0, 1);

	return 0;
}