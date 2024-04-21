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
    if (fileName == NULL)
        return -1;

    FILE *file = fopen(fileName, "r");
    if (file != NULL) {
        int64_t size = file_size(file);
        char *data = (char *) malloc((size + 1) * sizeof(char));
        memset(data, 0, (size + 1) * sizeof(char));

        fread(data, 1, size, file);
        *buffer = data;
        fclose(file);
        return size;
    }

    return -1;
}

_Bool is_digit(const char *digit, uint8_t size) {
    if (digit == NULL)
        return 0;

    uint8_t i = 0;
    _Bool result = 1;
    if (digit[i] == '-')
        i++;

    for (; i < size; i++) {
        result &= (digit[i] >= '0' && digit[i] <= '9');
    }
    return result;
}

_Bool is_value_separator(char alpha) {
    return (alpha != VALUE_SEPARATOR) && (alpha != RECORD_SEPARATOR) && (alpha != END_VALUE_SEPARATOR) &&
           (alpha != END_STRING);
}

_Bool is_record_separator(char alpha) {
    return (alpha != RECORD_SEPARATOR) && (alpha != END_STRING);
}

void skip_value_separator(char **source) {
    while ((*(*source)) == VALUE_SEPARATOR || (*(*source)) == END_VALUE_SEPARATOR) {
        *(*source)++;
    }
}

int32_t read_value(char **source, int8_t countDigit, int16_t min, int16_t max, int32_t *value) {
    char *digit = (char *) malloc(MAX_VALUE_BUFFER_LENGTH * sizeof(char));
    char *digitIndex = digit;
    memset(digit, 0, MAX_VALUE_BUFFER_LENGTH * sizeof(char));

    int32_t status = VALUE_OK;

    while (is_value_separator(*(*source))) {
        if (*(*source) != ' ')
            *digitIndex++ = *(*source);
        *(*source)++;
    }

    skip_value_separator(source);

    int32_t size = (int32_t)strlen(digit);
    if (countDigit == size || countDigit == NO_CONTROL_VALUE_LEN) {
        if (is_digit(digit, size)) {
            int32_t sourceValue = (int32_t)atoi(digit);
            if (sourceValue >= min && sourceValue <= max) {
                *value = sourceValue;
            } else
                status = ERROR_VALUE_OUT_RANGE;
        } else
            status = ERROR_VALUE_NO_DIGIT;
    } else
        status = ERROR_VALUE_DIGIT_LEN;

    free(digit);
    return status;
}

int64_t load_file(const char *fileName, Link *head) {
    char *rawData;
    int64_t readTotalByte = read_data(fileName, &rawData);
    if (readTotalByte != -1) {
        char *dataIndex = rawData;
        int64_t stringIndex = 0;

        while (*dataIndex != END_STRING) {
            Item data;
            int32_t stateRecord = VALUE_OK;
            stringIndex++;

            while (is_record_separator(*dataIndex)) {
                int32_t value = 0;
                stateRecord = read_value(&dataIndex, NO_CONTROL_VALUE_LEN, MIN_YEAR, MAX_YEAR, &value);
                if (stateRecord == VALUE_OK)
                    data.year = value;
                else
                    break;

                stateRecord = read_value(&dataIndex, NO_CONTROL_VALUE_LEN, MIN_MONTH, MAX_MONTH, &value);
                if (stateRecord == VALUE_OK)
                    data.month = value;
                else
                    break;

                stateRecord = read_value(&dataIndex, NO_CONTROL_VALUE_LEN, MIN_DAY, 31, &value);
                if (stateRecord == VALUE_OK)
                    data.day = value;
                else
                    break;

                stateRecord = read_value(&dataIndex, NO_CONTROL_VALUE_LEN, MIN_HOUR, MAX_HOUR, &value);
                if (stateRecord == VALUE_OK)
                    data.hour = value;
                else
                    break;

                stateRecord = read_value(&dataIndex, NO_CONTROL_VALUE_LEN, MIN_MINUTE, MAX_MINUTE, &value);
                if (stateRecord == VALUE_OK)
                    data.minute = value;
                else
                    break;

                stateRecord = read_value(&dataIndex, NO_CONTROL_VALUE_LEN, MIN_TEMPERATURE, MAX_TEMPERATURE, &value);
                if (stateRecord == VALUE_OK)
                    data.temperature = (int8_t)value;
                else
                    break;
            }

            if (stateRecord == VALUE_OK)
                push_item(head, data);
            else {
                printf("Format error in the line by number %ld.\n", stringIndex);
                while (is_record_separator(*dataIndex))
                    *dataIndex++;
            }

            if (*dataIndex != END_STRING)
                *dataIndex++;
        }

        return readTotalByte;
    }

    return -1;
}

StatisticData calc_statistic_by_month(Link head, uint8_t month) {
    Link tmp = head;

    StatisticData data;
    memset(&data, 0, sizeof(StatisticData));

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
        data.mean_temperature = (float)data.summa / (float)data.count;
    }
    return data;
}

StatisticData *calc_statistic(Link head) {
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
        totalData.mean_temperature = (float)totalData.summa / (float)totalData.count;
    }

    return totalData;
}

void print_help() {
    printf("Temperature statistics calculation program.\n");
    printf("   -h Description of the application functionality.\n");
    printf("   -f <filename.csv> csv input file for processing.\n");
    printf("   -m <month number> from 1 to 12. Only statistics for the specified month are displayed.\n");
}

void print_month_info(int monthNumber, StatisticData data) {
    printf("\nMonth:%d\n", monthNumber);
    printf("Records:%ld; Min:%d; Max:%d; Average:%.2f\n", data.count, data.min_temperature, data.max_temperature,
           data.mean_temperature);
}

void print_info(StatisticData *data) {
    for (int i = 0; i < 12; i++) {
        printf("\nMonth:%d\n", i + 1);
        printf("Records:%ld; Min:%d; Max:%d; Average:%.2f\n", data[i].count, data[i].min_temperature,
               data[i].max_temperature, data[i].mean_temperature);
    }
}

void print_total_info(StatisticData data) {
    printf("\nTotal:\n");
    printf("Records:%ld; Min:%d; Max:%d; Average:%.2f\n", data.count, data.min_temperature, data.max_temperature,
           data.mean_temperature);
}

#endif //TEMP_API_C
