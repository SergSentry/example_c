#ifndef TEMP_API_C
#define TEMP_API_C

#include "temp_api.h"

Link create_link(Item data) {
    Link tmp = (Link) malloc(sizeof(Link));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

void push_item(Link *head, Item data) {
    Link tmp = create_link(data);
    tmp->next = (*head);
    (*head) = tmp;
}

void delete_link(Link *head) {
    if (head != NULL) {
        Link prev = NULL;
        while ((*head)->next) {
            prev = (*head);
            (*head) = (*head)->next;
            free(prev);
        }
        free(*head);
    }
}

int64_t file_size(FILE *file) {
    int64_t position = ftell(file);
    fseek(file, 0, SEEK_END);
    int64_t size = ftell(file);
    fseek(file, position, SEEK_SET);
    return size;
}

int64_t read_data(const char *fileName, char **buffer) {
    return -1;
}

int32_t read_value(char **source, uint8_t countDigit, int8_t min, int8_t max, int8_t *value) {
    return -1;
}

int32_t load_file(const char *fileName, Link *head) {
    return -1;
}

StatisticData calc_statistic_by_month(const Link head, uint8_t month) {
    StatisticData data;
    memset(&data, 0, sizeof(StatisticData));

    return data;
}

StatisticData *calc_statistic(const Link head) {
    StatisticData *data = (StatisticData *) malloc(12 * sizeof(StatisticData));
    memset(data, 0, 12 * sizeof(StatisticData));

    return data;
}

StatisticData calc_total_statistic(StatisticData *data) {
    StatisticData totalData;
    memset(&totalData, 0, sizeof(StatisticData));

    return totalData;
}

void print_help() {
    printf("Temperature statistics calculation program.\n");
}

#endif //TEMP_API_C
