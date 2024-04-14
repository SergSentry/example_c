#include <unistd.h>

#include "temp_api.h"

int main(int argc, char *argv[]) {

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

    if (!showHelp) {
        if (fileName != NULL) {
            //open and read file data
        } else
            print_help();
    } else
        print_help();

    return 0;
}
