#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int smallest = INT_MAX, second_smallest = INT_MAX;
    int largest = INT_MIN, second_largest = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < second_smallest && arr[i] != smallest) {
            second_smallest = arr[i];
        }
        if(arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        }
        else if(arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }
    cout << "The second smallest element is: " << second_smallest << endl;
    cout << "The second largest element is: " << second_largest << endl;
    return 0;
}
