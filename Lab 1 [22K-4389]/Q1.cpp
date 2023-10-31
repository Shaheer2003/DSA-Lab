#include <iostream>

using namespace std;

class DynamicArray
{
public:
    int elements;
    int *ptr;
    DynamicArray() {}
    DynamicArray(int size)
    {
        ptr = new int[size];
        elements = size;
        fillarray();
        printarray();
    }

    void fillarray()
    {
        for (int i = 0; i < elements; i++)
        {
            cin >> ptr[i];
        }
    }

    void printarray()
    {
        for (int i = 0; i < elements; i++)
        {
            cout << ptr[i] << "\t";
        }
        cout << endl;
    }
    ~DynamicArray()
    {
        delete[] ptr;
        ptr = NULL;
        cout << "Destructor Called" << endl;
    }
};

int main()
{
    int size;
    cout << "Enter number of elements" << endl;
    cin >> size;
    DynamicArray array(size);
}
