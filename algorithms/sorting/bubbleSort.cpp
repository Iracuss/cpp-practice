#include <iostream>

void bubbleSort(int arr[], int size)
{
    for(int i = 0; i < size-1; i++)
    {
        for(int j = 0; j < size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

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

    bubbleSort(arr, size);

    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}