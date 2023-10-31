#include <iostream>
#include <vector>

using namespace std;

const int N = 5; // Size of the maze (adjust as needed)
const int target = 0; // Value of the middle cell

// Function to check if a cell is within bounds
bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < N;
}

// Recursive function to find a path
bool findPath(vector<vector<int>>& maze, int x, int y, vector<pair<int, int>>& path) {
    if (!isValid(x, y) || maze[x][y] == -1) {
        return false; // Invalid move or already visited cell
    }

    int steps = maze[x][y];
    path.push_back({x, y});

    if (x == N / 2 && y == N / 2 && steps == target) {
        return true; // Found a valid path to the middle cell
    }

    maze[x][y] = -1; // Mark the cell as visited

    // Try moving right
    if (findPath(maze, x, y + steps, path)) {
        return true;
    }

    // Try moving down
    if (findPath(maze, x + steps, y, path)) {
        return true;
    }

    maze[x][y] = steps; // Backtrack by restoring the original value
    path.pop_back(); // Remove the current cell from the path
    return false;
}

int main() {
    vector<vector<int>> maze = {
        {2, 1, 3, 2, 1},
        {3, 2, 1, 2, 3},
        {2, 1, 0, 2, 1},
        {1, 1, 3, 1, 1},
        {1, 1, 2, 2, 2}
    };

    vector<pair<int, int>> path;

    if (findPath(maze, 0, 0, path)) {
        cout << "Path found:" << endl;
        for (const auto& cell : path) {
            cout << "(" << cell.first << ", " << cell.second << ")" << endl;
        }
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}
