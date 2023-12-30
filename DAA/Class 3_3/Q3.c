#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high) {

        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

        clock_t start_time = clock();
        quickSort(arr, 0, size-1); 
        clock_t end_time = clock();
        
        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000; // Convert to milliseconds
        
        printf("%d\t\t%.4f\n", size, time_taken);
    }
                                             
    return 0;
}
