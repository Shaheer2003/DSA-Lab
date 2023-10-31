#include <iostream>
using namespace std;

bool isSafe(int** board, int r, int c, int N) {

    if ((r >= 0 && c >= 0) && (r < N && c < N) && (!board[r][c])){

        if (r - 1 >= 0 && c - 2 >= 0){
            if (board[r - 1][c - 2])
                return false;
        }

        if (r - 2 >= 0 && c - 1 >= 0) {
            if (board[r - 2][c - 1]) 
                return false;
            
        }

        if (r - 1 >= 0 && c + 2 < N) {
            if (board[r - 1][c + 2]) 
                return false;
        }

        if (r - 2 >= 0 && c + 1 < N) {
            if (board[r - 2][c + 1])
                return false;
        }

        if (r + 1 < N && c - 2 >= 0) {
            if (board[r + 1][c - 2])
                return false;
        }

        if (r + 2 < N && c - 1 >= 0) {
            if (board[r + 2][c - 1])
                return false;
        }

        if (r + 1 < N && c + 2 < N) {
            if (board[r + 1][c + 2])
                return false;
        }

        if (r + 2 < N && c + 1 < N) {
            if (board[r + 2][c + 1])
                return false;
        }
        return true;
    }
    return false;
}

bool nsqKnights(int** a, int r, int N, int& move) {
    if (move == ((N * N) / 2)) {
        return true;
    }
    if (r >= N) {
        r = 0;
    }
    for (int col = 0; col < N; col++) {

        if (isSafe(a, r, col, N)) {
            move++;
            a[r][col] = 1;
            if (nsqKnights(a, r + 1, N, move)) {
                return true;
            }
            a[r][col] = 0;
            move--;
        }
    }

    return false;
}

void printarray(int** arr, int N){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j] << " ";           
        }
        cout << endl;
    }
}

int main() {
    int N, move=0;
    cout << "enter N" << endl;
    cin >> N;
    int** board = new int*[N];
    for(int i = 0; i<N; i++){
        board[i] = new int[N];
    }
    //int board[4][4];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;       
        }
    }

    printarray(board,N);
    cout << endl;
    if (nsqKnights(board, 0, N, move)) {
        printarray(board,N);
        cout << "Knights Placed =  " << move << endl;
    }
    else cout << "Not Possible" << endl;
    

    return 0;
}