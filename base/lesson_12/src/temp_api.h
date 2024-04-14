#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

enum {
    YEAR_VALUE_LEN = 4,
    MIN_YEAR = 1900,
    MAX_YEAR = 2100,

    MONTH_VALUE_LEN = 2,
    MIN_MONTH = 1,
    MAX_MONTH = 12,

    DAY_VALUE_LEN = 2,
    MIN_DAY = 1,

    HOUR_VALUE_LEN = 2,
    MIN_HOUR = 0,
    MAX_HOUR = 23,

    MINUTE_VALUE_LEN = 2,
    MIN_MINUTE = 0,
    MAX_MINUTE = 59,

    TEMPERATURE_VALUE_LEN = 3,
    MIN_TEMPERATURE = -99,
    MAX_TEMPERATURE = 99,

    MAX_VALUE_BUFFER_LENGTH = 7,
    NO_CONTROL_VALUE_LEN = -1,
    VALUE_OK = 0,

    ERROR_VALUE_OUT_RANGE = 3,
    ERROR_VALUE_NO_DIGIT = 2,
    ERROR_VALUE_DIGIT_LEN = 1
};

typedef struct TemperatureRecord {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} TemperatureRecord;

typedef TemperatureRecord Item;

typedef struct Node *Link;

struct Node {
    Item data;
    Link next;
};

typedef struct StatisticData {
    uint64_t count;
    uint64_t summa;
    int8_t min_temperature;
    int8_t max_temperature;
    float mean_temperature;
} StatisticData;

typedef Link *Node;

Link create_link(Item data);

void push_item(Link *head, Item data);

void delete_link(Link *head);

int64_t file_size(FILE *file);

int32_t read_value(char **source, uint8_t countDigit, int8_t min, int8_t max, int8_t *value);

int64_t read_data(const char *fileName, char **buffer);

int32_t load_file(const char *fileName, Link *head);

StatisticData calc_statistic_by_month(const Link head, uint8_t month);

StatisticData *calc_statistic(const Link head);

StatisticData calc_total_statistic(StatisticData *data);

void print_help();

void print_month_info(int monthNumber, StatisticData data);

void print_info(StatisticData *data);

void print_total_info(StatisticData data);

#endif //TEMP_API_H