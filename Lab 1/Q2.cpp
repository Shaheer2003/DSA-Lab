#include <iostream>

using namespace std;

class DynamicArray
{
public:
    int rows;
    int columns;
    int **ptr;
    DynamicArray() {}
    DynamicArray(int row, int column)
    {
        ptr = new int *[row];
        rows = row;
        columns = column;

        for (int i = 0; i < row; i++)
        {
            ptr[i] = new int[column];
        }
        fillarray();
        printarray();
    }

    void fillarray()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cin >> ptr[i][j];
            }
        }
    }

    void printarray()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << ptr[i][j] << "\t";
            }
            cout << endl;
        }
    }

    ~DynamicArray()
    {
        for (int i = 0; i < columns; i++)
        {
            delete[] ptr[i];
        }
        delete[] ptr;
        ptr = NULL;
        cout << "Destructor Called" << endl;
    }
};

int main()
{
    int row, column;
    cout << "Enter rows and columns" << endl;
    cin >> row >> column;
    DynamicArray array(row, column);
}
