#include <iostream>
#include <string>
using namespace std;

class Sort{
public:
string *arr;
int len;

Sort(int n){
    arr = new string[n];
    len = n;
}

void bubblesort(){
    bool swapped = false;
    for(int i=0; i < len-1; i++){
        for(int j=0; j< len-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false) 
        break;
    }
}

void print(){
    for(int i=0; i < len; i++){
        cout << arr[i] << endl;
    }
}

};

int main(){

    Sort sort(3);
    sort.arr[0] = "bill";
    sort.arr[1] = "ball";
    sort.arr[2] = "bazball";
    sort.bubblesort();
    sort.print();
    

}