#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter the array element " << i + 1 << ": ";
        cin >> arr[i];
    }
    for(int j = 0; j < n - 1; j++) {
        int iMin = j;
        for(int i = j + 1; i < n; i++) {
            if(arr[i] < arr[iMin]) {
            iMin = i;
            }
        }
        if(iMin != j) {
            swap(arr[j], arr[iMin]);
        }
    }
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

