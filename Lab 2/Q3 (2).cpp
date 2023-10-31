#include <iostream>
using namespace std;


void InsertionSort(int arr[], int size) {
    for (int i = size - 2; i >= 0; i--) {
        int key = arr[i];
        int j = i + 1;

        while (j < size && arr[j] < key){
            arr[j - 1] = arr[j];
            j++;
        }

        arr[j - 1] = key;
    }
}

void print(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t"; 
    }
    cout << endl;
    
}

int main(){
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    InsertionSort(arr, n);
    print(arr, n);

}