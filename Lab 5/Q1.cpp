#include<iostream>
using namespace std;

int fibionacci(int n){
    if (n == 1 || n == 2)
    return n-1;
    return fibionacci(n-1) + fibionacci(n-2);
}


int main(){
    int n;
    cout << "Enter the n value" << endl;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cout << fibionacci(i) << " ";
    }

    return 0;
}