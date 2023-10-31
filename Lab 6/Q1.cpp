#include <iostream>
#include <time.h>
using namespace std;

void freq(int *arr, int size, int maxRange){
	int *count = new int[maxRange];
	int temp;
	for(int i=0; i<maxRange; i++){
		count[i] = 0;
	}
	for(int i=0; i<size; i++){
		temp = arr[i];
		temp--;
		count[temp]++;
	}
	for(int i=0; i<maxRange; i++){
		cout << "Occurence of " << i+1 << " " << count[i] << endl;
	}
	delete[] count;
}

void replace(int *arr, int  size, int find, int repl){
	bool found = false;
	for(int i=0; i<500; i++){
		if(arr[i] == find){
			found = true;
			arr[i] = repl;
		}
	}
	if(found) cout << "Successfully Replaced " << find << " with " << repl << endl;
	else cout << "Number Not Found!!" << endl;
}

void kthLargest(int *arr, int size, int k){
	int max, count=0;
	int visited[11]={0};
	for(int i=0; i<k; i++){
		max = -999;
		for(int j=0; j<size; j++){
			if(arr[j] > max && visited[arr[j]] == 0){
				max = arr[j];
			}
		}
		visited[max] = 1;
	}
	for(int i=0; i<size; i++){
		if(arr[i] == max){
			count++;
		}
	}
	cout << "The " << k << "th Largest element is " <<  max << " & appears " << count << " times " << endl;

}

int main(){
    srand(time(0));
	int find, repl,k;
    int *arr = new int[500];
    for (int i = 0; i < 500; i++){
        arr[i] = (rand() % 10)+ 1;
    }
    
	// for (int i = 0; i < 500; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    freq(arr, 500, 10);
	cout << "Enter k to find k Largest element" << endl;
	cin >> k;
	kthLargest(arr,500,k);
	cout << "Enter number to search" << endl;
	cin >> find;
	cout << "Enter which number to add" << endl;
	cin >> repl;
	replace(arr, 500, find, repl);
    delete[] arr;
    
	return 0;
}