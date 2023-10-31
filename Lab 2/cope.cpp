#include <iostream>
using namespace std;

void SubArray(int arr[], int n){
    int minIndex, maxIndex;
    int max = arr[0];
    int min = arr[n-1];
    bool isfound = false;
    for (int i = 1; i<n ; i++){
        if (arr[i] < max){
            maxIndex = i;
        }
        else max = arr[i];
    }
    for (int i = n-2; i>=0 ; i--){
        if (arr[i] > min){
            minIndex = i;
        }
        else min = arr[i];
    }
    cout << minIndex << endl 
         << maxIndex << endl;
}

int main() {
    int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    SubArray(arr, n);
    return 0;
}
