#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; 
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; 
}

int main() {
    srand(time(NULL));

    int data[100];
    for (int i = 0; i < 100; ++i) {
        data[i] = rand() % 101; 
    }

    bubbleSort(data, 100);

    int target = 50;

    int result = binarySearch(data, 0, 99, target);

    if (result >= 0) {
        printf("Target %d は %dです\n", target, result);
    } else {
        printf("Target %d ありませんでした.\n", target);
    }

    return 0;
}