#include <iostream>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int start, int end){
	int mid = start + (end-start)/2;
	int len1 = mid - start + 1;
    int len2 = end - mid;
    int *temp1 = new int[len1];
	int *temp2 = new int[len2];
	int k = start;
    for(int i=0; i<len1; i++) {
        temp1[i] = arr[k];
        k++;
    }
    
    k = mid+1;
    for(int i=0; i<len2; i++) {
        temp2[i] = arr[k];
        k++;
    }
    int i=0,j=0;
	k=start;
    while(i<len1 && j<len2){
    	if(temp1[i] < temp2[j]){
    		arr[k] = temp1[i];
    		i++;
			k++;
		}
		else{
			arr[k] = temp2[j];
			j++;
			k++;
		}
	}
	
	while(i<len1){
		arr[k] = temp1[i];
		i++;
		k++;
	}
	while(j<len2){
		arr[k] = temp2[j];
		j++;
		k++;
	}
	
	delete[] temp1;
	delete[] temp2;
}

void mergeSort(int *arr, int start, int end){
	if(start>=end)
		return;
	
	int mid = start + (end-start)/2;
	mergeSort(arr, start, mid);	
	mergeSort(arr, mid+1, end);
	merge(arr, start, end);
}

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

int main(){
	srand(time(0));
	int *arr = new int[10000];
	int *arr2 = new int[10000];
	for(int i=0; i<10000; i++){
		arr[i] = rand();
		arr2[i] = arr[i];
	}
	
	time_t start, end;
	time(&start);
	ios_base::sync_with_stdio(false);
	mergeSort(arr, 0, 10000-1);
	time(&end);
	double time_taken = double(end - start);
	cout << "MergeSort Time: " << fixed << time_taken << setprecision(5) << " Seconds " << endl;
	
	time(&start);
	ios_base::sync_with_stdio(false);
	bubbleSort(arr2,10000);
	time(&end);
	time_taken = double(end - start);
	cout << "BubbleSort Time: " << fixed << time_taken << setprecision(5) << " Seconds " << endl;

	delete[] arr;
	delete[] arr2;
}