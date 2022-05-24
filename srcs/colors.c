#include "fractal.h"

Uint32 **init_colors()
{
	Uint32 **colors;
	Grad_data red[3];
	Grad_data blue[3];
	Grad_data green[3];
	Grad_data grey[3];
	Grad_data all[4];
	Grad_data fire[7];
	Grad_data rand[7];

	colors = calloc(7, sizeof(int *));

	red[0].color = 0x00000000;
	red[1].color = 0xFF000000;
	red[2].color = 0x00000000;
	red[0].location = 0;
	red[1].location = 0.5;
	red[2].location = 1;

	green[0].color = 0x00000000;
	green[1].color = 0x00FF0000;
	green[2].color = 0x00000000;
	green[0].location = 0;
	green[1].location = 0.5;
	green[2].location = 1;
	
	blue[0].color = 0x00000000;
	blue[1].color = 0x0000FF00;
	blue[2].color = 0x00000000;
	blue[0].location = 0;
	blue[1].location = 0.5;
	blue[2].location = 1;
	
	grey[0].color = 0x00000000;
	grey[1].color = 0xFFFFFFFF;
	grey[2].color = 0x00000000;
	grey[0].location = 0;
	grey[1].location = 0.5;
	grey[2].location = 1;

	all[0].color = 0x00000000;
	all[1].color = 0xFFF74100;
	all[2].color = 0x96440000;
	all[3].color = 0x00000000;
	all[0].location = 0;
	all[1].location = 0.1;
	all[2].location = 0.5;
	all[3].location = 0.1;

	fire[0].color = 0x00000000;
	fire[1].color = 0xFF000000;
	fire[2].color = 0xFFA50000;
	fire[3].color = 0xFFD70000;
	fire[4].color = 0xFFFFFFFF;
	fire[5].color = 0xEE82EE00;
	fire[6].color = 0x00000000;
	fire[0].location = 0;
	fire[1].location = 0.1;
	fire[2].location = 0.3;
	fire[3].location = 0.5;
	fire[4].location = 0.7;
	fire[5].location = 0.9;
	fire[6].location = 1;

	rand[0].color = 0x00000000;
	rand[1].color = 0xFDFF0000;
	rand[2].color = 0x47F90000;
	rand[3].color = 0x00FFEC00;
	rand[4].color = 0xFF000000;
	rand[5].color = 0x8900FF00;
	rand[6].color = 0x00000000;
	rand[0].location = 0;
	rand[1].location = 0.1;
	rand[2].location = 0.2;
	rand[3].location = 0.45;
	rand[4].location = 0.6;
	rand[5].location = 0.75;
	rand[6].location = 1;

	colors[0] = GradArray_Get(LOD, create_gradient(red,  3));
	colors[1] = GradArray_Get(LOD, create_gradient(green,3));
	colors[2] = GradArray_Get(LOD, create_gradient(blue, 3));
	colors[3] = GradArray_Get(LOD, create_gradient(grey, 3));
	colors[4] = GradArray_Get(LOD, create_gradient(all,  4));
	colors[5] = GradArray_Get(LOD, create_gradient(fire, 7));
	colors[6] = GradArray_Get(LOD, create_gradient(rand, 7));

	return colors;
}