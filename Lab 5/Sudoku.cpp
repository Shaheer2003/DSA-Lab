#include <iostream>
using namespace std;

bool isSafe(int row, int col, int **board, int val, int N){
    for(int i=0; i<N; i++){
        if(board[row][i] == val)
            return false;
        if(board[i][col] == val)
            return false;
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
        return false;
    }
    return true;
}

bool sudokuSolver(int **board, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(board[i][j] == 0){
                for(int val=1; val<10; val++){
                    if(isSafe(i,j,board,val,N)){
                        board[i][j] = val;

                        if(sudokuSolver(board,N))
                            return true;
                        else board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;;
}

void printarray(int **arr, int N){
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
    int N;
    cout << "Enter Grid Size, (Multiple of 3)" << endl;
    cin >> N;;
    int** board = new int*[N];
    for(int i = 0; i<N; i++){
        board[i] = new int[N];
    }
    int** solution = new int*[N];
    for(int i = 0; i<N; i++){
        solution[i] = new int[N];
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)       
            board[i][j] = 0;
    printarray(board,N);
    cout << endl;
    sudokuSolver(board,N);
    printarray(board,N);
    cout << endl;


    return 0;
}