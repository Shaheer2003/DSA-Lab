#include<iostream>
using namespace std;

//Code DMA k sath crash horha tha isliye hard code krna para with static array


bool isSafe(int board[][4], int r, int c, int N){
    int i, j;
        for(i=0; i<c; i++){
            if(board[r][i] == 1)
            return false;
        }

    for(i=r, j=c; i>=0, j>=0; i--,j--){
            if(board[i][j] == 1)
            return false;
    }
    for(i=r, j=c; i<N && j>=0; i++,j--){
            if(board[i][j] == 1)
            return false;
    }
    return true;
}

bool Nqueen(int board[][4], int c, int N){
    if(c >= N){ 
        return true;
    }
    for(int i=0; i<N; i++){  
            if(isSafe(board,i,c,N)){
                board[i][c] = 1;
                if(Nqueen(board,c+1,N))
                    return true;
                board[i][c] = 0; 
            } 
    }
            return false; 
}

void printarray(int arr[][4], int N){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j] << " ";           
        }
        cout << endl;
    }
}

int main(){

    int N = 4 ; 
    // cout << "Enter N" << endl;
    // cin >> N;
    // int** board = new int*[N];
    // for(int i = 0; i<N; i++){
    //     board[i] = new int[N];
    // }
    int board[4][4];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;       
        }
    }

    printarray(board, N);
    cout << endl;
    bool solved = Nqueen(board,0,N);
    if(solved)
    printarray(board, N);
    else cout << "Not Possible" << endl;
    


    return 0;
}

