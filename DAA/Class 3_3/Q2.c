#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >-1 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }    
        arr[j + 1] = key;
    }
}
                                                                       
int main() {
    int num;
    int arr[100];

    printf("Enter the numebr of elements you wantt to enter into the array: ");
    scanf("%d", &num);

    printf("Enter the numbers: ");
    for (int i=0; i<num; i++){
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, num);

    printf("The sorted list: \n");
    for (int i=0; i<num; i++){
        printf("%d\n", arr[i]);
    }               

    return 0;
}
