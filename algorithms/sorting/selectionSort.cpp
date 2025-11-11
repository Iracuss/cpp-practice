#include <iostream>

void selectionSort(int arr[], int size)
{
    for(int i = 0; i < size-1; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {100, 40, 35, 20, 104, 54, 70, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, size);

    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}