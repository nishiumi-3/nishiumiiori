#include <stdio.h>

#define QUEUE_SIZE 5

struct Queue {
    char items[QUEUE_SIZE];
    int front, rear;
};

void initializeDequeue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(struct Queue *queue) {
    return (queue->front == 0 && queue->rear == QUEUE_SIZE - 1) ||
           (queue->front == queue->rear + 1);
}

void enqueueFront(struct Queue *queue, char value) {
    if (isFull(queue)) {
        
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
        queue->rear = 0;
    } else if (queue->front == 0) {
        queue->front = QUEUE_SIZE - 1;
    } else {
        queue->front--;
    }
    queue->items[queue->front] = value;
}

void enqueueRear(struct Queue *queue, char value) {
    if (isFull(queue)) {
        
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
        queue->rear = 0;
    } else if (queue->rear == QUEUE_SIZE - 1) {
        queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->items[queue->rear] = value;
}

char dequeueRear(struct Queue *queue) {
    
    char value = queue->items[queue->rear];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else if (queue->rear == 0) {
        queue->rear = QUEUE_SIZE - 1;
    } else {
        queue->rear--;
    }
    return value;
}

void enqueue(struct Queue *queue, char value) {
    enqueueRear(queue, value);
}

void displayQueue(struct Queue *queue) {
    
    int i = queue->front;
    do {
        printf("%c ", queue->items[i]);
        i = (i + 1) % QUEUE_SIZE;
    } while (i != (queue->rear + 1) % QUEUE_SIZE);
    printf("\n");
}

int main() {
    struct Queue myqueue;
    initializeDequeue(&myqueue);

    enqueueRear(&myqueue, 'a');
    enqueueRear(&myqueue, 'b');
    enqueueRear(&myqueue, 'c');
    enqueueRear(&myqueue, 'd');
    enqueueRear(&myqueue, 'e');

    displayQueue(&myqueue);

    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 'f');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 'g');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 'h');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 'i');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 'j');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 'k');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 'l');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 'm');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 'n');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 'o');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 'p');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 'q');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 'r');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 's');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 't');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 'u');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 'v');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 'w');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 's');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 'y');
    displayQueue(&myqueue);
    dequeueRear(&myqueue);
    enqueueRear(&myqueue, 'z');
    displayQueue(&myqueue);
    return 0;
}