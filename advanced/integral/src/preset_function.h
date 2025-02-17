#ifndef PRESET_FUNCTION_H
#define PRESET_FUNCTION_H

/// Функция вычисления f(x) = 0.6x + 3
/// \param x аргумент
/// \return f(x)
float first_func(float x);

/// Функция вычисления f(x) = (x − 2)^3 – 1
/// \param x аргумент
/// \return f(x)
float second_func(float x);

/// Функция вычисления f(x) = 3 / x
/// \param x аргумент
/// \return f(x)
float third_func(float x);

/// Функция вычисления f(x) = g(x)
/// где
/// f(x) = 0.6x + 3
/// g(x) = 3 / x
/// \param x аргумент
/// \return f(x) = g(x)
float first_third_func(float x);

/// Функция вычисления f(x) = g(x)
/// где
/// f(x) = 0.6x + 3
/// g(x) = (x − 2)^3 – 1
/// \param x аргумент
/// \return f(x) = g(x)
float first_second_func(float x);

/// Функция вычисления f(x) = g(x)
/// где
/// f(x) = (x − 2)^3 – 1
/// g(x) = 3 / x
/// \param x аргумент
/// \return f(x) = g(x)
float second_third_func(float x);

#endif //PRESET_FUNCTION_H