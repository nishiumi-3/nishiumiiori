#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void shuffle(int arr[], int n) {
    if (n > 1) {
        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

int main() {
    
    srand(time(NULL));

    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(data) / sizeof(data[0]);

    shuffle(data, size);

    printf("Shuffled Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    int target = 5;

    for (int result = -1; result < size; result++) {
        if (data[result] == target) {
            printf("Target %d は %dです\n", target, result);
            return 0;
        }
    }

    printf("Target %d not found in the array.\n", target);

    return 0;
}