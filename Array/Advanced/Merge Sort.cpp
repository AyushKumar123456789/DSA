// https://www.geeksforgeeks.org/problems/merge-sort/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int left[m - l + 1];
    int right[r - m];
    int i = 0;
    int a = l, b = m + 1;
    while (i < (m - l + 1))
    {
        left[i] = arr[l + i];
        i++;
    }
    i = 0;
    while (i < (r - m))
    {
        right[i] = arr[m + 1 + i];
        i++;
    }
    i = 0;
    int j = 0;
    int k = l;
    while (i < (m - l + 1) && j < (r - m))
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            k++;
        }
    }

    while (i < (m - l + 1))
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < (r - m))
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}