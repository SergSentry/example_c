#ifndef FUNCTION_H
#define FUNCTION_H

typedef float (*function_t)(float);

typedef float (*operation_t)(float, float, float, function_t);

#endif //FUNCTION_H