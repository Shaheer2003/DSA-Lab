#include <iostream>
using namespace std;
//we will use selection sort as it has the minimum number of swaps i.e 1 swap per iteration 
void SelectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex])
                minIndex=j;
            
        }
        int temp;
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout << endl;
}

int main(){
    int crates[5];
    
    cout << "Enter crates ID" << endl;
    for(int i=0;i<5;i++)
    cin >> crates[i];

    print(crates,5);
    
    SelectionSort(crates,5);
    print(crates,5);
}