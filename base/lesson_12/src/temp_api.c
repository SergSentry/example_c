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
    Link tmp = head;

    StatisticData data;
    memset(&data, 0, sizeof(StatisticData));

    long summ = 0;
    while (tmp) {
        if (tmp->data.month == month) {
            data.count++;
            data.max_temperature = tmp->data.temperature;
            data.min_temperature = tmp->data.temperature;
            data.summa += tmp->data.temperature;
            tmp = tmp->next;
            break;
        }
        tmp = tmp->next;
    }

    while (tmp) {
        if (tmp->data.month == month) {
            data.count++;
            data.summa += tmp->data.temperature;
            if (tmp->data.temperature > data.max_temperature)
                data.max_temperature = tmp->data.temperature;
            if (tmp->data.temperature < data.min_temperature)
                data.min_temperature = tmp->data.temperature;
        }
        tmp = tmp->next;
    }

    if (data.count > 0) {
        data.mean_temperature = data.summa / data.count;
    }
    return data;
}

StatisticData *calc_statistic(const Link head) {
    Link tmp = head;

    StatisticData *data = (StatisticData *) malloc(12 * sizeof(StatisticData));
    memset(data, 0, 12 * sizeof(StatisticData));

    for (int i = 0; i < 12; i++)
        data[i] = calc_statistic_by_month(head, i + 1);

    return data;
}

StatisticData calc_total_statistic(StatisticData *data) {
    StatisticData totalData;
    memset(&totalData, 0, sizeof(StatisticData));

    totalData.count += data[0].count;
    totalData.min_temperature = data[0].min_temperature;
    totalData.max_temperature = data[0].max_temperature;
    totalData.summa += data[0].summa;

    for (int i = 1; i < 12; i++) {
        totalData.count += data[i].count;

        if (data[i].max_temperature > totalData.max_temperature)
            totalData.max_temperature = data[i].max_temperature;
        if (data[i].min_temperature < totalData.min_temperature)
            totalData.min_temperature = data[i].min_temperature;

        totalData.summa += data[i].summa;
    }

    if (totalData.count > 0) {
        totalData.mean_temperature = totalData.summa / totalData.count;
    }

    return totalData;
}

void print_help() {
    printf("Temperature statistics calculation program.\n");
}

void print_month_info(int monthNumber, StatisticData data) {
    printf("\nMonth:%d\n", monthNumber);
    printf("Records:%d; Min:%d; Max:%d; Average:%.2f\n", data.count, data.min_temperature, data.max_temperature,
           data.mean_temperature);
}

void print_info(StatisticData *data) {
    for (int i = 0; i < 12; i++) {
        printf("\nMonth:%d\n", i + 1);
        printf("Records:%d; Min:%d; Max:%d; Average:%.2f\n", data[i].count, data[i].min_temperature,
               data[i].max_temperature, data[i].mean_temperature);
    }
}

void print_total_info(StatisticData data) {
    printf("\nВсего:\n");
    printf("Records:%d; Min:%d; Max:%d; Average:%.2f\n", data.count, data.min_temperature, data.max_temperature,
           data.mean_temperature);
}

#endif //TEMP_API_C
