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

/// Процедура выполнения интерактивного теста
void test_handler() {
    printf("Процедура выполнения интерактивного теста\n");
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