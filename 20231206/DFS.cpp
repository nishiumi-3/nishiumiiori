#include <stdio.h>
#include <stdbool.h>

/* 迷路のサイズ */
#define MEIRO_WIDTH 4
#define MEIRO_HEIGHT 4
#define MAX_PASSED_POS 64
#define PATH 0 /* 通路 */
#define WALL 1 /* 壁 */
#define GOAL 2 /* ゴール */
#define PASSED 3 /* 通過したマス */

/* 管理するデータの上限個数 */
#define MAX_NUM (MEIRO_WIDTH * MEIRO_HEIGHT)

#define STACK_SIZE MAX_NUM


/* マスの位置情報 */
typedef struct POS {
    int i; /* マスのi座標 */
    int j; /* マスのj座標 */
} POS_T;

POS_T passed_positions[MAX_PASSED_POS];
int passed_positions_count = 0;

/* スタック構造体 */
typedef struct STACK {
    /* データの最後尾 */
    int tail;
    /*スタックされているデータ*/
    POS_T data[STACK_SIZE];
} STACK_T;

STACK_T stack;

/*迷路を表す配列*/
static int maze[MEIRO_HEIGHT][MEIRO_WIDTH]  
{
    {1,1,0,1},
    {1,0,0,0},
    {1,0,0,0},
    {1,1,1,2}
    
};

/*スタックを初期化する関数*/
void initStack(STACK_T *stack){

    /*ここでスタックを空にする*/
    stack->tail = -1;
}

/*PUSHする関数*/
void push(STACK_T *stack, POS_T *input) {
    /*スタックが満杯なら何もせず関数終了*/
    if (stack->tail < STACK_SIZE - 1 && maze[input->j][input->i] != WALL && maze[input->j][input->i] != PASSED) {
        stack->data[++stack->tail] = *input;
        printf("Pushed: (%d, %d)\n", input->i, input->j);
    } else {
        printf("Cannot push to (%d, %d). Stack is full or the position is a wall or already passed.\n", input->i, input->j);
    }
}

bool checkpush(int i, int j) {
    bool ret = true;

    if (i < 0 || i >= MEIRO_WIDTH || j < 0 || j >= MEIRO_HEIGHT || maze[j][i] == WALL || maze[j][i] == PASSED) {
        ret = false;
    }

    return ret;
}

/*POPする関数*/
POS_T *pop(STACK_T *stack){
    POS_T *ret;

    /*スタックが空なら何もせずに関数終了*/
    if (stack->tail >= 0) {
        POS_T *ret = &(stack->data[stack->tail--]);
        printf("Popped: (%d, %d)\n", ret->i, ret->j);
        return ret;
    } else {
        printf("Stack is empty. Cannot pop.\n");
        return NULL;
    }
}

bool check(int i, int j) {
    bool ret = true;

    if (i < 0 || i >= MEIRO_WIDTH || j < 0 || j >= MEIRO_HEIGHT) {
        ret = false;
    }

    if (maze[j][i] == WALL) {
        ret = false;
    }

    if (maze[j][i] == PASSED) {
        ret = false;
    }

    return ret;
}

void savePassedPosition(int i, int j) {
    if (passed_positions_count < MAX_PASSED_POS) {
        passed_positions[passed_positions_count].i = i;
        passed_positions[passed_positions_count].j = j;
        passed_positions_count++;
    }
}

bool search(int s_i, int s_j) {

    POS_T pos;
    bool ret = false;  /*最初は到達していないと仮定*/

    if (check(s_i, s_j)) {
        pos.i = s_i;
        pos.j = s_j;
        push(&stack, &pos);
        savePassedPosition(s_i, s_j);
    }

    while (true) {
        int i, j;

        POS_T *next = pop(&stack);
        if (next == NULL) {
            printf("Stack is empty. Exiting.\n");
            break;
        }

        i = next->i;
        j = next->j;

        if (maze[j][i] == GOAL) {
            ret = true;  // ゴールに到達した場合に true に設定
            printf("Reached the goal at (%d, %d).\n", i, j);
            savePassedPosition(i, j);  // ゴールも通過地点として保存
            break;
        }

        maze[j][i] = PASSED;

        if (i == 5 && j == 1) {
            printf("Reached position (5, 1). Exiting.\n");
            break;
        }

        if (checkpush(i, j - 1)) {
            pos.i = i;
            pos.j = j - 1;
            push(&stack, &pos);
            savePassedPosition(i, j - 1);
        }

        if (checkpush(i, j + 1)) {
            pos.i = i;
            pos.j = j + 1;
            push(&stack, &pos);
            savePassedPosition(i, j + 1);
        }

        if (checkpush(i - 1, j)) {
            pos.i = i - 1;
            pos.j = j;
            push(&stack, &pos);
            savePassedPosition(i - 1, j);
        }

        if (checkpush(i + 1, j)) {
            pos.i = i + 1;
            pos.j = j;
            push(&stack, &pos);
            savePassedPosition(i + 1, j);
        }
    }

    return ret;
}


int main() {

    initStack(&stack);

    /*スタート位置を(1,1)として開始*/
    if (search(1, 1)) {
       printf("通過した場所:\n");
        for (int i = 0; i < passed_positions_count; i++) {
            printf("(%d, %d)\n", passed_positions[i].i, passed_positions[i].j);
        }
    } 
    return 0;
}

