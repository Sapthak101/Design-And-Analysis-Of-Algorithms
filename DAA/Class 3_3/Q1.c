#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return -1; 
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int i = left - 1;
        
        for (int j = left; j < right; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        int temp = arr[i + 1];
        arr[i + 1] = arr[right];
        arr[right] = temp;
        
        int partitionIndex = i + 1;
        
        quickSort(arr, left, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, right);
    }
}

int main() {
    srand(time(NULL)); 
    
    int sizes[] = {100, 500, 1000, 1500, 4000, 4500, 5000, 7000, 8000, 10000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("Array Size\tTime Taken (ms)\n");
    
    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        int arr[size];
        
        for (int j = 0; j < size; j++) {
            arr[j] = rand() % 10000; 
        }

        quickSort(arr, 0, size - 1); 
        
        int target = arr[rand() % size]; 
        
        clock_t start_time = clock();
        int result = binarySearch(arr, size, target);
        clock_t end_time = clock();
        
        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000; 
        
        printf("%d\t\t%.4f\n", size, time_taken);
    }
    
    return 0;
}
