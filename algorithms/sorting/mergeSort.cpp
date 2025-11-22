#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right)
{
    int l1 = mid - left + 1;
    int r1 = right - mid;

    std::vector<int> l(l1), r(r1);

    for(int i = 0; i < l1; i++)
    {
        l[i] = arr[left + i];
    }
    for(int i = 0; i < r1; i++)
    {
        r[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0;
    int k = left;

    while(i < l1 && j < r1)
    {
        if(l[i] <= r[j])
        {
            arr[k] = l[i];
            i++;
        } else {
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    while(i < l1)
    {
        arr[k] = l[i];
        i++;
        k++;
    }
    while(j < r1)
    {
        arr[k] = r[j];
        j++;
        k++; 
    }
}

void mergeSort(std::vector<int>& arr, int left, int right)
{
    if(left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main()
{
    std::vector<int> arr = {37, 4, 92, 18, 76, 53, 11, 85};
    int n = arr.size();
    mergeSort(arr, 0, n-1);

    for(int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}