#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge (int A[], int l, int mid, int h)
{
    int i, j, k;
    int B[10000];
    i=l;
    j=mid+1;
    k=l;

    while(i<=mid && j<=h)
    {
        if (A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    for (;i<=mid;i++)
        B[k++]=A[i];
    for (;j<=h;j++)
        B[k++]=A[j];
    for (i=l;i<=h;i++)
        A[i]=B[i];
}

void mergeSort(int A[], int l, int h)
{
    if (l<h)
    {
        int mid;
        mid=(l+h)/2;
        mergeSort(A,l,mid);
        mergeSort(A,mid+1,h);
        merge(A,l,mid,h);
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
        mergeSort(arr, 0, size-1); 
        clock_t end_time = clock();
        
        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000; 
        
        printf("%d\t\t%.4f\n", size, time_taken);
    }
    
    return 0;
}