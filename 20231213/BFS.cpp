#include <stdio.h>

#define MEIRO_WIDTH 4
#define MEIRO_HEIGHT 4
#define MAX_PASSED_POS 64
#define PATH 0 
#define WALL 1 
#define GOAL 2 
#define PASSED 3

#define MAX_NUM (MEIRO_WIDTH * MEIRO_HEIGHT)

#define QUEUE_SIZE MAX_NUM

typedef struct POS {
    int i;
    int j; 
} POS_T;

POS_T passed_positions[MAX_PASSED_POS];
int passed_positions_count = 0;
typedef struct QUEUE {
    int front, rear;
    POS_T data[QUEUE_SIZE];
} QUEUE_T;

QUEUE_T queue;

typedef struct STACK {
    int tail;
    POS_T data[MAX_NUM];
} STACK_T;

STACK_T stack;

static int maze[MEIRO_HEIGHT][MEIRO_WIDTH] =
{
    {1,1,0,1},
    {1,0,0,0},
    {1,0,0,0},
    {1,1,1,2}
};

void initQueue(QUEUE_T *queue) {
    queue->front = queue->rear = -1;
}

int isQueueEmpty(QUEUE_T *queue) {
    return (queue->front == -1);
}

int isQueueFull(QUEUE_T *queue) {
    return ((queue->rear + 1) % QUEUE_SIZE == queue->front);
}

void enqueue(QUEUE_T *queue, POS_T *input) {
    if (!isQueueFull(queue) && maze[input->j][input->i] != WALL && maze[input->j][input->i] != PASSED) {
        if (isQueueEmpty(queue)) {
            queue->front = queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % QUEUE_SIZE;
        }

        queue->data[queue->rear] = *input;
        printf("Enqueued: (%d, %d)\n", input->i, input->j);
    } else {
        printf("Cannot enqueue to (%d, %d). Queue is full or the position is a wall or already passed.\n", input->i, input->j);
    }
}

POS_T dequeue(QUEUE_T *queue) {
    POS_T ret;

    if (!isQueueEmpty(queue)) {
        ret = queue->data[queue->front];

        if (queue->front == queue->rear) {
            
            initQueue(queue);
        } else {
            queue->front = (queue->front + 1) % QUEUE_SIZE;
        }

        printf("Dequeued: (%d, %d)\n", ret.i, ret.j);
    } else {
        printf("Queue is empty. Cannot dequeue.\n");
    }

    return ret;
}

int checkEnqueue(int i, int j) {
    int ret = 1;

    if (i < 0 || i >= MEIRO_WIDTH || j < 0 || j >= MEIRO_HEIGHT || maze[j][i] == WALL || maze[j][i] == PASSED) {
        ret = 0;
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

int bfs(int start_i, int start_j) {
    POS_T pos;
    int ret = 0; 
    if (checkEnqueue(start_i, start_j)) {
        pos.i = start_i;
        pos.j = start_j;
        enqueue(&queue, &pos);
        savePassedPosition(start_i, start_j);
    }

    while (!isQueueEmpty(&queue)) {
        POS_T current = dequeue(&queue);
        int i = current.i;
        int j = current.j;

        if (maze[j][i] == GOAL) {
            ret = 1; 
            printf("Reached the goal at (%d, %d).\n", i, j);
            savePassedPosition(i, j); 
            break;
        }

        maze[j][i] = PASSED;

        if (i == 5 && j == 1) {
            printf("Reached position (5, 1). Exiting.\n");
            break;
        }

        if (checkEnqueue(i, j - 1)) {
            pos.i = i;
            pos.j = j - 1;
            enqueue(&queue, &pos);
            savePassedPosition(i, j - 1);
        }

        if (checkEnqueue(i, j + 1)) {
            pos.i = i;
            pos.j = j + 1;
            enqueue(&queue, &pos);
            savePassedPosition(i, j + 1);
        }

        if (checkEnqueue(i - 1, j)) {
            pos.i = i - 1;
            pos.j = j;
            enqueue(&queue, &pos);
            savePassedPosition(i - 1, j);
        }

        if (checkEnqueue(i + 1, j)) {
            pos.i = i + 1;
            pos.j = j;
            enqueue(&queue, &pos);
            savePassedPosition(i + 1, j);
        }
    }

    return ret;
}

int main() {
    initQueue(&queue);
    if (bfs(1, 1)) {
        printf("通過した場所:\n");
        for (int i = 0; i < passed_positions_count; i++) {
            printf("(%d, %d)\n", passed_positions[i].i, passed_positions[i].j);
        }
    }

    return 0;
}
