#ifndef GRADIENT_H
# define GRADIENT_H

# include <stdio.h>
# include <stdlib.h>

# include <math.h>
# include "SDLX/SDLX.h"
# include "lerp.h"

# define GAUSS_X_DIST 5
# define GAUSS_Y_DIST 5
# define SMOOTHNESS 100 //100 is default, this is the number of colors in a full gradient
# define NCOLORS 	5 // Number of colors in the gradient 0 for full gradient -however many colors the screen can fit-

typedef struct Grad_Data
{
	Uint32 	color;
	double 	location;
}				Grad_data;

typedef struct	s_gradient
{
	int 			ncolors;
	Grad_data		*colors;
}					Gradient;

Gradient 	create_gradient(Grad_data *data, int ncolors);
SDL_Texture *render_grad_texture(Gradient grad, int ncolors, int h, int w);

Uint32		*GradArray_Get(int amount, Gradient grad);
int			num_Scale(int input, int from_min, int from_max, int to_min, int to_max);
int			blurr_pixel(int x,int y, gauss_matrix matrix, int x_bound, int y_bound);
void		blurr_texture(SDL_Rect area, gauss_matrix mat, SDL_Surface *surf);

#endif
