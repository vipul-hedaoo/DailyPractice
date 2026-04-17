#include <iostream>
#include <functional>
using namespace std;

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Partition function (lambda)
    auto partition = [&](int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for(int j = low; j < high; j++)
        {
            if(arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        return i + 1;
    };

    // QuickSort function (lambda with recursion)
    function<void(int,int)> quickSort = [&](int low, int high) {
        if(low < high)
        {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    };

    // Call QuickSort
    quickSort(0, n - 1);

    // Print result
    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}