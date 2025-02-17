/*
 С заданной точностью ε вычислить площадь плоской фигуры, ограниченной тремя кривыми:
    1. f(x) = 0.6x + 3
    2. f(x) = (x − 2)^3 – 1
    3. f(x) = 3 / x
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "function.h"
#include "preset_function.h"
#include "math_function.h"

#define ARG_KEY_HELP        "-help" //Аргумент вывода справочной информации
#define ARG_KEY_TEST        "-test" //Аргумент интерактивного тестирования
#define ARG_KEY_EPSILON_ONE "-eps1" //Аргумент указания точности вычисления точек пересечения кривых.
#define ARG_KEY_EPSILON_TWO "-eps2" //Аргумент указания точности вычисления интеграла


/// Процедура вывода справочной информации
void help_handler() {
    printf("Программа вычисления с заданной точностью ε площади плоской фигуры, ограниченной тремя кривыми:\n");
    printf("  1. f(x) = 0.6x + 3\n");
    printf("  2. f(x) = (x − 2)^3 – 1\n");
    printf("  3. f(x) = 3/x\n");
    printf("\nВ группу кривых входит гипербола расположенная в первой и третьей четверти плоскости. \
            \nРасчет площади фигуры выполняется для первой четверти плоскости.\n");
    printf("\nПараметры запуска программы:\n");
    printf("  -help  -вывод данного сообщения;\n");
    printf("  -test  -интерактивное тестирование кривых;\n");
    printf("  -eps1  -точность вычисления точек пересечения кривых. По умолчанию равна 0.001;\n");
    printf("  -eps2  -точность вычисления интеграла. По умолчанию равна 0.001\n\n");
}

/// Функция поиска индекса слова в массиве аргументов
/// \param argc Кол-во аргументов
/// \param argv Массив аргументов
/// \param str  слово для поиска
/// \return Значение индекса слова иначе -1
int32_t index_of_arg(int32_t argc, char *argv[], const char *str) {
    for (int32_t index = 1; index < argc; index++) {
        if (strcmp(argv[index], str) == 0)
            return index;
    }

    return -1;
}

/// Функция вывода меню выбора исполняемой функции:
/// 1. f(x) = 0.6x + 3
/// 2. f(x) = (x − 2)^3 – 1
/// 3. f(x) = 3/x
/// \return Указатель на исполняемую функцию
function_t show_menu_and_select_function() {
    uint32_t input_function = 4;
    do {
        printf("Введите номер функции:\n");
        printf("  1. f(x) = 0.6x + 3\n");
        printf("  2. f(x) = (x − 2)^3 – 1\n");
        printf("  3. f(x) = 3/x\n");
        printf("  4. Exit\n");
        scanf("%u", &input_function);
    } while (input_function > 4 || input_function == 0);

    function_t function = NULL;
    switch (input_function) {
        case 1:
            printf("f(x) = 0.6x + 3\n");
            break;
        case 2:
            printf("f(x) = (x − 2)^3 – 1\n");
            break;
        case 3:
            printf("f(x) = 3/x\n");
            break;
    }

    return function;
}

/// Функция вывода меню выбора исполняемой операции:
/// 1. вычисление корней
/// 2. вычисление интеграла
/// \return Указатель на исполняемую операции
operation_t show_menu_and_select_operation() {
    uint32_t input_function = 3;
    do {
        printf("Введите номер операции:\n");
        printf("  1. Вычисление корней\n");
        printf("  2. Вычисление интеграла\n");
        printf("  3. Exit\n");
        scanf("%u", &input_function);
    } while (input_function > 3 || input_function == 0);

    operation_t operation = NULL;
    switch (input_function) {
        case 1:
            printf("Вычисление корней\n");
            break;
        case 2:
            printf("Вычисление интеграла\n");
            break;
    }

    return operation;
}

/// Процедура выполнения интерактивного теста
void test_handler() {
    function_t function = show_menu_and_select_function();

    if (function != NULL) {
        operation_t operation = show_menu_and_select_operation();
        if (operation != NULL) {
            float a, b, eps, result;
            printf("Введите значение a:\n");
            scanf("%f", &a);

            //Проверка значения b
            do {
                printf("Введите значение b:\n");
                scanf("%f", &b);
                if (b < a)
                    printf("Значение b должно быть больше значения a (%f)\n", a);
            } while (b < a);

            //Проверка значения epsilon
            do {
                printf("Введите значение epsilon:\n");
                scanf("%f", &eps);
                if (eps <= 0 || eps >= 1)
                    printf("Значение epsilon должно быть больше 0 и меньше 1\n");
            } while (eps <= 0 || eps >= 1);

            //Выполнение операции с заданными параметрами и указанной функцией
            result = operation(a, b, eps, function);

            printf("%f\n", result);
        }
    }
}

/// Основная функция
/// \param argc Кол-во аргументов
/// \param argv Массив аргументов
/// \return Код возврата функции
int32_t main(int argc, char *argv[]) {
    
    // Переменная задающая точность вычисления точек пересечения кривых.
    float eps_one = 0.001f;
    // Переменная задающая точность вычисления интеграла
    float eps_two = 0.001f;

    // Проверка на аргумент вывода справочной информации
    if (index_of_arg(argc, argv, ARG_KEY_HELP) > 0) {
        help_handler();
        return 0;
    }

    // Проверка на аргумент интерактивного тестирования
    if (index_of_arg(argc, argv, ARG_KEY_TEST) > 0) {
        test_handler();
        return 0;
    }

    // Проверка на аргумент определения точности вычисления точек пересечения кривых.
    int32_t index_eps_one = index_of_arg(argc, argv, ARG_KEY_EPSILON_ONE);
    if (index_eps_one > 0 && argc > index_eps_one) {
        eps_one = atof(argv[index_eps_one + 1]);
        printf("eps_one %f\n", eps_one);
    }

    // Проверка на аргумент определения точности вычисления интеграла
    int32_t index_eps_two = index_of_arg(argc, argv, ARG_KEY_EPSILON_TWO);
    if (index_eps_two > 0 && argc > index_eps_two) {
        eps_two = atof(argv[index_eps_two + 1]);
        printf("eps_two %f\n", eps_two);
    }

    return 0;
}