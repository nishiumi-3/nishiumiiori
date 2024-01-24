#include <stdio.h>

#define STACK_SIZE 5

struct Stack {
    char items[STACK_SIZE];
    int top;
};

void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

int isFull(struct Stack *stack) {
    return stack->top == STACK_SIZE - 1;
}

void push(struct Stack *stack, char value) {
    if (isFull(stack)) {
       
        return;
    }
    stack->items[++stack->top] = value;
}

char pop(struct Stack *stack) {
    if (stack->top == -1) {
       
        return '\0'; 
    }
    return stack->items[stack->top--];
}


int main() {
    struct Stack myStack;
    initializeStack(&myStack);


    push(&myStack, 'a');
    push(&myStack, 'b');
    push(&myStack, 'c');
    push(&myStack, 'd');
    push(&myStack, 'e');

    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
        
    }
    printf("\n");

    pop(&myStack);
    push(&myStack, 'f');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
        
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 'g');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
        
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 'h');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
       
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 'i');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
       
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 'j');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
        
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 'k');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
        
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 'l');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
        
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 'm');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
        
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 'n');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
        
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 'o');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
        
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 'p');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
        
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 'q');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
        
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 'r');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
        
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 's');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
        
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 't');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
        
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 'u');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
        
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 'v');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
        
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 'w');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
        
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 'x');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
       
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 'y');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
        
    }
    printf("\n");
    pop(&myStack);
    push(&myStack, 'z');
    for (int i = myStack.top; i >= 0; --i) {
        printf("%c ", myStack.items[i]);
        
    }
    printf("\n");
    return 0;
}