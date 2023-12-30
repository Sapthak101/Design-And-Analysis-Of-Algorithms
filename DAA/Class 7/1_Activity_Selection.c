#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort algorithm to sort activities based on finish times
void bubbleSort(int s[], int f[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (f[j] > f[j + 1]) {
                swap(&f[j], &f[j + 1]);
                swap(&s[j], &s[j + 1]);
            }
        }
    }
}

void printMaxActivities(int s[], int f[], int n) {
    printf("Following activities are selected\n");

    // Sort activities based on finish times
    bubbleSort(s, f, n);

    int i, j;
    i = 0;
    printf("%d ", i+1);

    // Consider rest of the activities
    for (j = 1; j < n; j++) {
        // If this activity has a start time greater than or
        // equal to the finish time of the previously selected
        // activity, then select it
        if (s[j] >= f[i]) {
            printf("%d ", j+1);
            i = j;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    int s[n], f[n];

    printf("Enter the start times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    printf("Enter the finish times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &f[i]);
    }

    // Function call
    printMaxActivities(s, f, n);
    return 0;
}