#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MIN_Y  2
double DELAY = 0.1;

enum {
    LEFT = 1, UP, RIGHT, DOWN, STOP_GAME = KEY_F(10)
};

enum {
    CONTROLS=2, MAX_TAIL_SIZE = 100, START_TAIL_SIZE = 3, MAX_FOOD_SIZE = 20, FOOD_EXPIRE_SECONDS = 10, SEED_NUMBER = 3
};

enum{
    SNAKE = 1,
    FOOD = 2
};

// Здесь храним коды управления змейкой
struct control_buttons {
    int down;
    int up;
    int left;
    int right;
} control_buttons;

struct control_buttons default_controls[CONTROLS] = {{KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT},
                                                    {'S', 'W', 'A', 'D'}};

/*
 Голова змейки содержит в себе
 x,y - координаты текущей позиции
 direction - направление движения
 tsize - размер хвоста
 *tail -  ссылка на хвост
 */
typedef struct snake_t {
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
    struct control_buttons *controls;
} snake_t;

/*
 Хвост это массив состоящий из координат x,y
 */
typedef struct tail_t {
    int x;
    int y;
} tail_t;

struct food {
    int x;
    int y;
    time_t put_time;
    char point;
    uint8_t enable;
} food[MAX_FOOD_SIZE];

void setColor(int objectType){
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    switch (objectType){
        case 1:{ // SNAKE
            attron(COLOR_PAIR(1));
            break;
        }
        case 2:{ // FOOD
            attron(COLOR_PAIR(2));
            break;
        }
    }
}

void initTail(struct tail_t t[], size_t size) {
    struct tail_t init_t = {0, 0};
    for (size_t i = 0; i < size; i++) {
        t[i] = init_t;
    }
}

void initHead(struct snake_t *head, int x, int y) {
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
}

void initSnake(snake_t *head, size_t size, int x, int y) {
    tail_t *tail = (tail_t *) malloc(MAX_TAIL_SIZE * sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y);
    head->tail = tail; // прикрепляем к голове хвост
    head->tsize = size + 1;
    head->controls = default_controls;
}

void initFood(struct food f[], size_t size) {
    struct food init = {0, 0, 0, 0, 0};
    int max_y = 0, max_x = 0;
    getmaxyx(stdscr, max_y, max_x);
    for (size_t i = 0; i < size; i++) {
        f[i] = init;
    }
}

/*
 Движение головы с учетом текущего направления движения
 */
void go(struct snake_t *head) {
    char ch = '@';
    int max_x = 0, max_y = 0;
    setColor(SNAKE);
    getmaxyx(stdscr, max_y, max_x); // macro - размер терминала
    mvprintw(head->y, head->x, " "); // очищаем один символ
    switch (head->direction) {
        case LEFT:
            if (head->x <= 0) // Циклическое движение, чтобы не
// уходить за пределы экрана
                head->x = max_x;
            mvprintw(head->y, --(head->x), "%c", ch);
            break;
        case RIGHT:
            if (head->x >= max_x)
                head->x = 0;
            mvprintw(head->y, ++(head->x), "%c", ch);
            break;
        case UP:
            if (head->y <= 0)
                head->y = max_y;
            mvprintw(--(head->y), head->x, "%c", ch);
            break;
        case DOWN:
            if (head->y >= max_y)
                head->y = 0;
            mvprintw(++(head->y), head->x, "%c", ch);
            break;
        default:
            break;
    }
    refresh();
}

void changeDirection(struct snake_t *snake, const int32_t key) {
    for (size_t i = 0; i < CONTROLS; i++) {
        struct control_buttons ctrl = snake->controls[i];

        if (key == ctrl.down) {
            snake->direction = DOWN;
            break;
        }
        else if (key == ctrl.up) {
            snake->direction = UP;
            break;
        }
        else if (key == ctrl.right) {
            snake->direction = RIGHT;
            break;
        }
        else if (key == ctrl.left) {
            snake->direction = LEFT;
            break;
        }
    }
}

/*
 Движение хвоста с учетом движения головы
 */
void goTail(struct snake_t *head) {
    char ch = '*';
    setColor(SNAKE);
    mvprintw(head->tail[head->tsize - 1].y, head->tail[head->tsize - 1].x, " ");
    for (size_t i = head->tsize - 1; i > 0; i--) {
        head->tail[i] = head->tail[i - 1];
        if (head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}

/*
 Check state uroboros
*/
_Bool isCrash(struct snake_t *head) {
    for (size_t i = 1; i < head->tsize; i++)
        if (head->x == head->tail[i].x && head->y == head->tail[i].y)
            return 1;
    return 0;
}

/*
  Check hitting the tail
*/
int checkDirection(struct snake_t *snake, int32_t dir, int32_t key) {
    for (size_t i = 0; i < CONTROLS; i++) {
        struct control_buttons ctrl = snake->controls[i];

        if (ctrl.down == key && dir == UP || ctrl.up == key && dir == DOWN || ctrl.left == key && dir == RIGHT ||
            ctrl.right == key && dir == LEFT) {
            return 0;
        }
    }
    

    return 1;  
}

void addTail(struct snake_t *head) {
    if (head == NULL || head->tsize > MAX_TAIL_SIZE) {
        mvprintw(0, 0, "Can't add tail");
        return;
    }
    head->tsize++;
}

void putFoodSeed(struct food *fp) {
    int max_x = 0, max_y = 0;
    char spoint[2] = {0};
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(fp->y, fp->x, " ");
    fp->x = rand() % (max_x - 1);
    fp->y = rand() % (max_y - 2) + 1; //Не занимаем верхнюю строку
    fp->put_time = time(NULL);
    fp->point = '$';
    fp->enable = 1;
    spoint[0] = fp->point;
    setColor(FOOD);
    mvprintw(fp->y, fp->x, spoint);
}

void putFood(struct food f[], size_t number_seeds) {
    for (size_t i = 0; i < number_seeds; i++) {
        putFoodSeed(&f[i]);
    }
}

void refreshFood(struct food f[], int nfood) {
    int max_x = 0, max_y = 0;
    char spoint[2] = {0};
    getmaxyx(stdscr, max_y, max_x);
    for (size_t i = 0; i < nfood; i++) {
        if (f[i].put_time) {
            if (!f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS) {
                putFoodSeed(&f[i]);
            }
        }
    }
}

_Bool haveEat(struct snake_t *head, struct food f[]) {
    for (size_t i = 0; i < MAX_FOOD_SIZE; i++)
        if (f[i].enable && head->x == f[i].x && head->y == f[i].y) {
            f[i].enable = 0;
            return 1;
        }
    return 0;
}

_Bool update(snake_t *snake, int key_pressed) {
    
    clock_t begin = clock();
    
    if (checkDirection(snake, snake->direction, key_pressed))
        changeDirection(snake, key_pressed);

    if (isCrash(snake)) {
        return 1;
    }

    go(snake);
    goTail(snake);

    if (haveEat(snake, food)) {
        addTail(snake);
    }

    refreshFood(food, SEED_NUMBER);

    while ((double)(clock() - begin)/CLOCKS_PER_SEC < DELAY)
    {}

    return 0;
}

int main()
{
    snake_t *snake = (snake_t *) malloc(sizeof(snake_t));
    
    initSnake(snake, START_TAIL_SIZE, 10, 10);
    initFood(food, MAX_FOOD_SIZE);

    initscr();
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw();                // Откдючаем line buffering
    noecho();            // Отключаем echo() режим при вызове getch
    curs_set(FALSE);    //Отключаем курсор
    mvprintw(0, 0, "Use arrows for control. Press 'F10' for EXIT");
    
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);

    putFood(food, SEED_NUMBER);
    timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле
    
    int key_pressed = 0;
    while (key_pressed != STOP_GAME) {
        key_pressed = toupper(getch()); // Считываем клавишу

        if (update(snake, key_pressed))
            break;
    }

    setColor(SNAKE);

    free(snake->tail);
    free(snake);
    
    getch();
    
    endwin(); // Завершаем режим curses mod

    return 0;
}