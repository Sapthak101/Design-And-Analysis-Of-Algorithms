#include <iostream>
using namespace std;

// Function to swap two elements
void EXCHANGE(int &p, int &q) {
    int temp = p;
    p = q;
    q = temp;
}

// Function to rotate the array right by 1 position for the first p2 elements
void ROTATE_RIGHT(int *p1, int p2) {
    if (p2 <= 0) {
        return;
    }

    for (int i = p2 - 1; i > 0; --i) {
        EXCHANGE(p1[i], p1[i - 1]);
    }
}

int main() {
    int n1;
    cout<<"Enter the number of elements you want to enter: ";
    cin>>n1;
    int arr[n1];

    for (int i=0; i<n1; i++)
        cin>>arr[i];
    
    cout<<"Enter position to rotate : ";
    int p2;
    cin>>p2;

    int n = sizeof(arr) / sizeof(arr[0]);
    p2 = min(p2, n);

    ROTATE_RIGHT(arr, p2);

    cout << "Rotated array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}