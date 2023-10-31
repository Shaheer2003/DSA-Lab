#include <iostream>
using namespace std;

void subArray(int arr[], int n)
{ // O(n^2)
    int minIndex, maxIndex;
    bool isfound = false;
    for (int i = 0; i < n - 1 && isfound == false; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                isfound = true;
                break;
            }
        }
    }
    isfound = false;
    for (int i = n - 1; i >= 0 && isfound == false; i--)
    {
        maxIndex = i;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[maxIndex])
            {
                isfound = true;
                break;
            }
        }
    }

    cout << "The subarray lies b/w Indexes " << minIndex << " & "
         << maxIndex << endl;
}

void print(int arr[], int n)
{
}

int main()
{
    int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    int arr2[] = {0, 1, 15, 25, 6, 7, 30, 40, 50};
    int len = sizeof(arr) / sizeof(arr[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    subArray(arr, len);
    subArray(arr2, len2);

    return 0;
}