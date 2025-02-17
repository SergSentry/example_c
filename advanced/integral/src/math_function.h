#ifndef MATH_FUNCTION_H
#define MATH_FUNCTION_H

#include <stdio.h>
#include <math.h>

#include "function.h"

int signF(float x, function_t f);

float rootFindDiv2(float xl, float xr, float eps, function_t f);

#endif //MATH_FUNCTION_H