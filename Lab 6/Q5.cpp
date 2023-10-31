#include <iostream>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int *arr, int n){
	bool swapped;
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}
		if(!swapped) break;
	}
}

double checkUniform(int *arr, int size, int maxRange){
	int *freq = new int[maxRange];
	int temp,notSame=0;
    double error = 0;
    int maxCount = INT_MIN;
	for(int i=0; i<maxRange; i++){
		freq[i] = 0;
	}
	for(int i=0; i<size; i++){
		temp = arr[i];
		temp--;
		freq[temp]++;
	}
    for(int i=0; i<maxRange; i++){
		if (freq[i] > maxCount){
            maxCount = freq[i];
        }
	}
    for(int i=0; i<maxRange; i++){
        if((freq[i]!=maxCount ) && (freq[i]!=0)){
            notSame++;
        }
    }
    error = (maxCount - notSame) * (100/maxRange);
    error = 100 - error;

    
	delete[] freq;
    return error;
}

int binarySearch(int *arr, int size, int key) {
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;
    while(start <= end) {
        if(arr[mid] == key)
            return mid;
        
        if(key > arr[mid])
            start = mid + 1;
        
        else
            end = mid - 1;

        mid = start + (end-start)/2;
    }
    return -1;
}

bool interpolSearch(int *arr, int size, int key) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (((high - low) / (arr[high] - arr[low])) * (key - arr[low]));
        if (mid < 0 || mid >= size)
            return false;
        
        if (arr[mid] == key)
            return true;
        
        else if (arr[mid] < key)
            low = mid + 1;
        
        else 
            high = mid - 1;  
    }
    return false;
}

int main(){
    srand(time(0));
    double uniformity;
    for(int h = 0; h<100; h++){
        int *arr = new int[10000];
        for (int i = 0; i < 10000; i++){
            arr[i] = (rand()%100) + 1;
        }
        bubbleSort(arr, 10000);
        uniformity = checkUniform(arr, 10000, 100);
        cout << "Uniformity of Array "<< uniformity << setprecision(2) << " % " << endl;
        time_t start, end;
        
        start = clock();
        ios_base::sync_with_stdio(false);
        binarySearch(arr,10000,69);
        end = clock();
        
        double time_taken = double(end - start);
        cout << "BinSearch Time: " << fixed << time_taken << setprecision(5) << " Seconds " << endl;

        start = clock();
        
        ios_base::sync_with_stdio(false);
        interpolSearch(arr,10000,69);
        
        end = clock();
        time_taken = double(end - start);
        cout << "InterpolSearch Time: " << fixed << time_taken << setprecision(5) << " Seconds " << endl;
        
        delete[] arr;
    }


    return 0;
}