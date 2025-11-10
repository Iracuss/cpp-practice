#include <iostream>

int linearSearch(int arr[], int size, int target)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 50};

    int size = sizeof(arr) / sizeof(arr[0]);

    int result = linearSearch(arr, size, 50);

    if(result == -1)
    {
        std::cout << "Target not in array\n";
    } else {
        std::cout << "Target in array at index " << result << std::endl;
    }
    return 0;
}