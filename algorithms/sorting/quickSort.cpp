#include <iostream>

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int left, int right)
{
    int pivotVal = arr[left];

    int i = left + 1;
    int j = right;

    while(true)
    {
        while(i <= right && arr[i] < pivotVal)
        {
            i++;
        }
        while(arr[j] > pivotVal)
        {
            j--;
        }
        if(i >= j)
        {
            break;
        }
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    swap(arr[left], arr[j]);
    return j;
}

void quickSortHelper(int arr[], int left, int right)
{
    if(left < right)
    {
        // Get the pivot then recursively call on the left and right of pivot
        int pivot = partition(arr, left, right);
        quickSortHelper(arr, left, pivot-1);
        quickSortHelper(arr, pivot+1, right);
    }
}

void quickSort(int arr[], int size)
{
    quickSortHelper(arr, 0, size-1);
}

int main()
{
    int arr[] = {37, 4, 92, 18, 76, 53, 11, 85, 29, 67, 44, 9, 100, 58, 23, 71, 16, 49, 82, 31, 7, 63, 94, 27, 55};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, size);

    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}