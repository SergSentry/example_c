#include "preset_function.h"

float first_func(float x) {
    return 0.6f * x + 3.0f;
}

float second_func(float x) {
    float sub = x - 2.0f;
    return sub * sub * sub - 1.0f;
}

float third_func(float x) {
    return x != 0 ? 3.0f / x : 0;
}

float first_third_func(float x) {
    return (0.6f * x + 3.0f) * x - 3.0f;
}

float first_second_func(float x) {
    float sub = x - 2.0f;
    return (sub * sub * sub - 1.0f - 3.0f) / .6f - x;
}

float second_third_func(float x) {
    float sub = x - 2.0f;
    return (sub * sub * sub - 1.0f) * x - 3.0f;
}
