#include "Gradient/gradient.h"

int			num_Scale(int input, int from_min, int from_max, int to_min, int to_max)
{
	int		result;
	int		range;
	double	tmp;

	range = (from_max - from_min);

	tmp = input - from_min;
	tmp /= range;
	tmp *= (to_max - to_min);
	result = tmp + to_min;

	return result;
}