#include <unistd.h>

#include "temp_api.h"

int main(int argc, char *argv[]) {
    Link listHead = NULL;

    int key = 0;
    char *fileName;
    int monthNumber = -1;
    _Bool showHelp = 0;

    while ((key = getopt(argc, argv, "f:m::h::")) != -1) {
        switch (key) {
            case 'f':
                fileName = optarg;
                break;
            case 'm':
                monthNumber = atoi(optarg);
                break;
            case 'h':
                showHelp = 1;
                break;
            default:
                showHelp = 1;
                break;
        }
    }

    if (!showHelp)
    {
        if (fileName != NULL)
        {
            if (load_file(fileName, &listHead) != -1)
            {
                if (monthNumber >= 1 && monthNumber <= 12)
                {
                    StatisticData total = calc_statistic_by_month(listHead, monthNumber);
                    print_month_info(monthNumber, total);
                }
                else if (monthNumber == -1)
                {
                    StatisticData *data = calc_statistic(listHead);
                    print_info(data);

                    StatisticData total = calc_total_statistic(data);
                    print_total_info(total);
                }
                else
                    printf("Ошибка: Номер месяца должен быть числом от 1 до 12.");

                delete_link(&listHead);
            }
            else
                printf("Ошибка: Проверте имя файла и путь к нему.");
        }
        else
            print_help();
    }
    else
        print_help();

    return 0;
}
