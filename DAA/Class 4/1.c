#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition (int A[], int l, int h)
{
    int pivot=A[l];
    int i=l;
    int j=h;
    do{
        do{
            i++;
        }while(A[i]<=pivot);
        do{
            j--;
        }while(A[j]>pivot);
        if (i<j){
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }while(i<j);
    
    int temp=A[j];
    A[j]=A[l];
    A[l]=temp;

    return j;
}

void quickSort(int A[], int l, int h)
{
    int j;
    if (l<h)
    {
        j=partition(A,l,h);
        quickSort(A,l,j);
        quickSort(A,j+1,h);
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
        
        arr[size]=100000;
        
        clock_t start_time = clock();
        quickSort(arr, 0, size+1); 
        clock_t end_time = clock();
        
        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000; 
        
        printf("%d\t\t%.4f\n", size, time_taken);
    }
    
    return 0;
}