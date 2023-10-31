#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int *arr, int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void binarySearch(int *arr, int size, int cols, int key) {
    bool found = false;
    int start = 0;
    int end = size-1;
    int rowIndex = -1, colIndex = -1;
    int mid = start + (end-start)/2;

    while(start <= end) {

        if(arr[mid] == key) {
            rowIndex = mid / cols;
            colIndex = mid % cols; 
        }

        //go to right wala part
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{ //key < arr[mid]
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
    cout << "Found at Index [" << rowIndex << ", " << colIndex << "]" << endl;
}



int main(){
    srand(time(0));
    int rows, cols, key;
    cout << "Enter Rows and Columns " << endl;
    cin >> rows >> cols;
    int TotalElem = rows*cols;
    int ** arr = new int*[rows];
    int *newArr = new int[TotalElem];
    for(int i=0; i<rows; i++){
        arr[i] = new int[cols];
    }
    for(int i=0; i<TotalElem; i++){ 
        int row1 = i / cols;
        int col1 = i % cols;
        arr[row1][col1] = (rand() % 1000 )+ 1;
        newArr[i] = arr[row1][col1];
    }
    bubbleSort(newArr, TotalElem);
    for(int i=0; i<TotalElem; i++){
        cout << newArr[i] << " ";
    }
    cout << endl;
    cout << "What number to find (b/w 1-1000)" << endl;
    cin >> key;
    binarySearch(newArr, TotalElem, cols, key);
    for(int i=0; i<rows; i++){
       delete[] arr[i];
    }
    delete[] arr;
    delete[] newArr;
    return 0;
}