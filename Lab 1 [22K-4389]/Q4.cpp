#include <iostream>

using namespace std;

class DynamicJaggedArray
{
public:
    int rows;
    int *columns;
    int **ptr;
    DynamicJaggedArray() {}
    DynamicJaggedArray(int row, int *column)
    {
        ptr = new int *[row];
        rows = row;
        columns = column;

        for (int i = 0; i < row; i++)
        {
            ptr[i] = new int[column[i]];
        }
        fillarray();
        printarray();
    }

    void fillarray()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns[i]; j++)
            {
                cin >> ptr[i][j];
            }
        }
    }

    void printarray()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns[i]; j++)
            {
                cout << ptr[i][j] << "\t";
            }
            cout << endl;
        }
    }

    ~DynamicJaggedArray()
    {
        for (int i = 0; i < columns[i]; i++)
        {
            delete[] ptr[i];
            ptr[i] = NULL;
        }
        delete[] ptr;
        delete[] columns;
        columns = NULL;
        ptr = NULL;
        cout << "Destructor Called" << endl;
    }
};

int main()
{
    int row;
    cout << "Enter rows" << endl;
    cin >> row;
    int *column = new int[row];
    for (int i = 0; i < row; i++)
    {
        cout << "Enter columns for each row" << endl;
        cin >> column[i];
    }
    DynamicJaggedArray array(row, column);
}
