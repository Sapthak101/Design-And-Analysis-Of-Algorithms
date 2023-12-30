#include <bits/stdc++.h>
using namespace std;

void fillPrefixSum(int arr[], int n, int prefixSum[])
{
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];
}

int main()
{
    int n1;
    cout<<"Enter the number of elements you want to enter: ";
    cin>>n1;
    int arr[n1];
    cout<<"enter the elements: \n";

    for (int i=0; i<n1; i++)
        cin>>arr[i];

    int n = sizeof(arr) / sizeof(arr[0]);
    int prefixSum[n];
    
    fillPrefixSum(arr, n, prefixSum);
    
    for (int i = 0; i < n; i++)
        cout << prefixSum[i] << " ";
}