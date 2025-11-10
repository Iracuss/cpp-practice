#include <iostream>

int binarySearchNested(int arr[], int target, int left, int right)
{
    if(left > right)
    {
        return -1;
    }

    int middle = (left + right) / 2;

    if(arr[middle] == target)
    {
        return middle;
    }

    if(arr[middle] > target)
    {
        // left side
        return binarySearchNested(arr, target, left, middle-1);

    } else {
        // right side
        return binarySearchNested(arr, target, middle+1, right);
    }
}

int binarySearch(int arr[], int size, int target)
{
    return binarySearchNested(arr, target, 0, size-1);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,10,11,30,33,40,42};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, size, 30);

    if(result == -1)
    {
        std::cout << "target not in array\n";
    } else {
        std::cout << "target at index " << result << std::endl;
    }

    return 0;
}