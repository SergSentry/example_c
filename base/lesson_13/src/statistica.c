#include <unistd.h>
#include <locale.h>
#include "temp_api.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "utf8");

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
                if (optarg != NULL)
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

    if (!showHelp) {
        if (fileName != NULL) {
            if (load_file(fileName, &listHead) != -1) {
                if (monthNumber >= 1 && monthNumber <= 12) {
                    StatisticData total = calc_statistic_by_month(listHead, monthNumber);
                    print_month_info(monthNumber, total);
                } else if (monthNumber == -1) {
                    StatisticData *data = calc_statistic(listHead);
                    print_info(data);

                    StatisticData total = calc_total_statistic(data);
                    print_total_info(total);
                } else
                    printf("Error: The month number must be a number from 1 to 12.");

                delete_link(&listHead);
            } else
                printf("Error: Check the file name and path to it.");
        } else
            print_help();
    } else
        print_help();

    return 0;
}
