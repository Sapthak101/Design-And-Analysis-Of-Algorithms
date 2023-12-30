#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
 
// A structure to represent a job
typedef struct Job {
   
    char id; // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on
                // deadline
} Job;
 
// This function is used for sorting all jobs according to
// profit
int compare(const void* a, const void* b)
{
    Job* temp1 = (Job*)a;
    Job* temp2 = (Job*)b;
    return (temp2->profit - temp1->profit);
}
 
// Find minimum between two numbers.
int min(int num1, int num2)
{
    return (num1 > num2) ? num2 : num1;
}
 
// Returns maximum profit from jobs
void printJobScheduling(Job arr[], int n)
{
    // Sort all jobs according to decreasing order of profit
    qsort(arr, n, sizeof(Job), compare);
 
    int result[n]; // To store result (Sequence of jobs)
    bool slot[n]; // To keep track of free time slots
 
    // Initialize all slots to be free
    for (int i = 0; i < n; i++)
        slot[i] = false;
 
    // Iterate through all given jobs
    for (int i = 0; i < n; i++) 
    {
             
        // Find a free slot for this job (Note that we start
        // from the last possible slot)
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            
            // Free slot found
            if (slot[j] == false) 
            {
                result[j] = i; // Add this job to result
                slot[j] = true; // Make this slot occupied
                break;
            }
        }
    }

    // Print the result
    int profit=0;
    for (int i = 0; i < n; i++){
        if (slot[i]){
            profit=profit+arr[result[i]].profit;
            printf("%c ", arr[result[i]].id);
        }
    }
    printf("\nThe profit is %d", profit);
}

// Driver's code
int main()
{
    Job arr[] = { { 'a', 2, 900 },
                  { 'b', 1, 19 },
                  { 'c', 2, 177 },
                  { 'd', 1, 500 },
                  { 'e', 3, 100 } };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", sizeof(arr));
    printf("%d", n);
    printf("Following is maximum profit sequence of jobs \n");
 
    // Function call
    printJobScheduling(arr, n);
    return 0;
}