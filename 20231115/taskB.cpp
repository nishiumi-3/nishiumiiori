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

    int data[100];
    for (int i = 0; i < 100; ++i) {
        data[i] = rand() % 100; 
    }

    shuffle(data, 100);

    for (int i = 0; i < 100; ++i) {
        for (int j = 99; j >= i + 1; --j) {
            int valueA = data[i];
            int valueB = data[j];

            if (valueA > valueB) {
                int max = valueA;
                int min = valueB;
                data[i] = min;
                data[j] = max;
            }
        }
    }

    printf("Sorted Array: ");
    for (int i = 0; i < 100; ++i) {
        printf("%d ", data[i]);
         printf("\n ");
    }
    printf("\n");

    return 0;
}