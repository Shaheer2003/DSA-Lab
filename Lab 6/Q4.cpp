#include <iostream>
#include<bits/stdc++.h>
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

int partition( int *arr, int s, int e) {
    int pivot = arr[s];
    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <=pivot) {
            cnt++;
        }
    }
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);
    
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= pivot) 
        {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int *arr, int s, int e) {
    if(s >= e) 
        return ;
    int p = partition(arr, s, e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);

}

void CountSort(int *arr, int n, int pos) {
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        count[(arr[i] / pos) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / pos) % 10] - 1] = arr[i];
        count[(arr[i] / pos) % 10]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int *arr, int n) {
    int max = *max_element(arr,arr+n);
    for (int pos = 1;max/pos > 0;pos *= 10) {
        CountSort(arr, n, pos);
    }
}

int main(){
    srand(time(0));
    double msTime = 0;
    double qsTime = 0;
    double rsTime = 0;
    double min[3] = {INT_MAX}; // 0 for Merge, 1 for Quick, 2 for Radix
    double max[3] = {INT_MIN};
    
    for(int i=0; i<100; i++){
        int *arr = new int[10000];
        int *arr2 = new int[10000];
        int *arr3 = new int[10000];
        for(int i=0; i<10000; i++){
            arr[i] = rand();
            arr2[i] = arr[i];
            arr3[i] = arr[i];
        }
        
        time_t start, end;
        //time(&start);
        start = clock();
        ios_base::sync_with_stdio(false);
        mergeSort(arr, 0, 10000-1);
        //time(&end);
        end = clock();
        double time_taken = double(end - start);
        msTime += time_taken;
        if(time_taken < min[0]){
            min[0] = time_taken;
        }
        if(time_taken > max[0]){
            max[0] = time_taken;
        }
       // cout << "MergeSort Time: " << fixed << time_taken << setprecision(5) << " Seconds " << endl;
        
        //time(&start);
        start = clock();
        ios_base::sync_with_stdio(false);
        quickSort(arr2,0,10000-1);
        //time(&end);
        end = clock();
        time_taken = double(end - start);
        qsTime += time_taken;
        if(time_taken < min[1]){
            min[1] = time_taken;
        }
        if(time_taken > max[1]){
            max[1] = time_taken;
        }
       // cout << "QS Time: " << fixed << time_taken << setprecision(5) << " Seconds " << endl;

        //time(&start);
        start = clock();
        ios_base::sync_with_stdio(false);
        radixSort(arr3,10000);
       // time(&end);
        end = clock();
        time_taken = double(end - start);
        rsTime += time_taken;
        if(time_taken < min[2]){
            min[2] = time_taken;
        }
        if(time_taken > max[2]){
            max[2] = time_taken;
        }
      //  cout << "RS Time: " << fixed << time_taken << setprecision(5) << " Seconds " << endl;

        delete[] arr;
        delete[] arr2;
        delete[] arr3;
    }
    cout << "MergeSort : " << endl 
         << "Best Time : " << fixed << min[0] << setprecision(5) << " Seconds " << endl
         << "Average Time : " << fixed << msTime/100 << setprecision(5) << " Seconds " << endl
         << "Worst Time : " << fixed << max[0] << setprecision(5) << " Seconds " << endl;
    
    cout << "QuickSort : " << endl 
         << "Best Time : " << fixed << min[1] << setprecision(5) << " Seconds " << endl
         << "Average Time : " << fixed << qsTime/100 << setprecision(5) << " Seconds " << endl
         << "Worst Time : " << fixed << max[1] << setprecision(5) << " Seconds " << endl;

    cout << "RadixSort : " << endl 
         << "Best Time : " << fixed << min[2] << setprecision(5) << " Seconds " << endl
         << "Average Time : " << fixed << rsTime/100 << setprecision(5) << " Seconds " << endl
         << "Worst Time : " << fixed << max[2] << setprecision(5) << " Seconds " << endl;




    return 0;
}