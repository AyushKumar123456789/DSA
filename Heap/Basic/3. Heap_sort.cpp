#include <bits/stdc++.h>
using namespace std;

class Max_Heap
{
public:
    static void insert(int val, vector<int> &arr)
    {
        arr.push_back(val);
        int n = arr.size() - 1;
        while (1)
        {
            int parent = n / 2;
            if (n != 0 && arr[parent] < arr[n])
            {
                swap(arr[parent], arr[n]);
                n = parent;
            }
            else
            {
                return;
            }
        }
    }
    static void Heapify_top_to_bottom(vector<int> &arr, int n, int idx)
    {
        while (1)
        {
            int largest = idx;
            int l = 2 * idx + 1;
            int r = 2 * idx + 2;
            if (l < n && arr[l] > arr[largest])
            {
                largest = l;
            }
            if (r < n && arr[r] > arr[largest])
            {
                largest = r;
            }
            if (largest != idx)
            {
                swap(arr[largest], arr[idx]);
                idx = largest;
            }
            else
            {
                return;
            }
        }
    }

    static void Delete(vector<int> &arr)
    {
        if (arr.size() == 0)
        {
            cout << "Empty Max_Heap" << endl;
            return;
        }
        else
        {
            arr[0] = arr[arr.size() - 1];
            arr.pop_back();
            Max_Heap::Heapify_top_to_bottom(arr, arr.size(), 0);
        }
    }
    static void print(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
void Heap_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Max_Heap::Heapify_top_to_bottom(arr, n, i);
    }
    for (int sz = n - 1; sz >= 0; sz--)
    {
        swap(arr[0], arr[sz]);
        Max_Heap::Heapify_top_to_bottom(arr, sz, 0);
    }
}

int main()
{
    vector<int> arr = {4, 5, 2, 22, 11, 1, 66, 6};
    Heap_sort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
