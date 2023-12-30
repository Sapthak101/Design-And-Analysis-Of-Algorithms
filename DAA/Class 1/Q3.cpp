#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() 
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }   

    unordered_map<int, int> cntduplicates;
    int totalDuplicates = 0;
    int MRE= 0;
    int maxCount = 0;

    for (int num : arr) {
        cntduplicates[num]++;
    }
    
    for (auto num : cntduplicates) {
        cout<<num.first<<"  "<<num.second<<endl;
    }

    for (auto it : cntduplicates) {
        if (it.second > 1) {
            totalDuplicates++;
        }
        if (it.second > maxCount) {
            maxCount = it.second;
            MRE= it.first;
        }
    }
    cout << "Total number of duplicate elements: " << totalDuplicates << endl;
    cout << "Most repeating element in the array: " << MRE<< endl;
}   