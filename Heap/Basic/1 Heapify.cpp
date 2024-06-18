#include <bits/stdc++.h>
using namespace std;

/*
Max Heap
*/

void Heapify_one_node(vector<int> &arr, int idx, int n)
{
    int largest = idx;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != idx)
    {
        swap(arr[idx], arr[largest]);

        Heapify_one_node(arr, largest, n);
    }
}

void Heapify(vector<int> &arr)
{
    int n = arr.size();
    int start = n / 2 - 1;
    for (int i = start; i >= 0; i--)
    {
        Heapify_one_node(arr, i, n);
    }
}

int main()
{

    vector<int> arr = {1,
                       3,
                       5,
                       4,
                       6,
                       13,
                       10,
                       9,
                       8,
                       15,
                       17};

    Heapify(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}