#include<iostream>
#include<time.h>

using namespace std;

bool isSafe(int** maze, int r, int c, int N){
    if(r < N && c < N && maze[r][c] == 0){
        return true;
    }
    return false;
}

bool solveMaze(int** maze, int r, int c, int N, int** solution){
    
    if(r == (N-2) && c == 0){
        solution[r][c] = 0; 
        return true;
    }

    if(isSafe(maze,r,c,N)){
        if(solution[r][c] == 0){
            return false;
        }
        solution[r][c] = 0;
        if(solveMaze(maze,r,c-1,N,solution)){
            return true;
        }    
        
        if(solveMaze(maze,r+1,c,N,solution)){
            return true;
        }     

        if(solveMaze(maze,r,c+1,N,solution)){
            return true;
        }

        if(solveMaze(maze,r-1,c,N,solution)){
            return true;
        }

        solution[r][c] = 1;
        return false;
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

int main(){
    //starting (1, N-1)
    //ending (N-2, 0)
    int N ; 
    int rnd;
    cout << "Enter N" << endl;
    cin >> N;
    srand(time(0));
    // int maze[5][5]; 
    // int solution[5][5];
    int** maze = new int*[N];
    for(int i = 0; i<N; i++){
        maze[i] = new int[N];
    }
    int** solution = new int*[N];
    for(int i = 0; i<N; i++){
        solution[i] = new int[N];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            rnd = rand()%5;
            if(rnd < 4){
            maze[i][j] = 0;
            }
            else {
            maze[i][j] = 1;
            }   
            solution[i][j] = 1;         
        }
    }
    maze[1][N-1] = 0;
    maze[N-2][0] = 0;
    printarray(solution, N);
    cout << endl;
    printarray(maze, N);
    cout << endl;
    if(solveMaze(maze,1,N-1,N, solution))
    printarray(solution, N);
    else cout << "Not Possible" << endl;



    return 0;
}

