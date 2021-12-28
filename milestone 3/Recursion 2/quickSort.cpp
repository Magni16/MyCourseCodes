#include <iostream>
using namespace std;

int partitionArray(int arr[], int si, int ei)
{
    int pivot = arr[si];

    int count = 0;
    for (int i = si + 1; i <= ei; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotIndex = si + count;
    int temp = arr[si];
    arr[si] = arr[pivotIndex];
    arr[pivotIndex] = temp;

    int i = si;
    int j = ei;

    while (i <= pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)

        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int si, int ei)
{
    if (si > ei)
    {
        return;
    }
    int pivotIndex = partitionArray(arr, si, ei);
    quickSort(arr, si, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, ei);
}

void quickSort(int arr[], int n)
{

    quickSort(arr, 0, n - 1);
}