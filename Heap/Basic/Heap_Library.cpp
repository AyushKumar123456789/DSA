/*
This is a Heap library which contains all functions of priority queue.
where , i have to just import this and write My_pritority_queue<int> pq;
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class My_pritority_queue
{
public:
    vector<T> arr;
    My_pritority_queue()
    {
    }
    My_pritority_queue(vector<T> &v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            arr.push_back(v[i]);
        }
        for (int i = arr.size() / 2 - 1; i >= 0; i--)
        {
            Heapify_top_to_bottom(arr, arr.size(), i);
        }
    }
    void push(T val)
    {
        arr.push_back(val);
        Heapify_bottom_to_top(arr, arr.size() - 1);
    }
    void pop()
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
            Heapify_top_to_bottom(arr, arr.size(), 0);
        }
    }
    T top()
    {
        if (arr.size() == 0)
        {
            cout << "Empty Max_Heap" << endl;
            return -1;
        }
        return arr[0];
    }
    int size()
    {
        return arr.size();
    }
    void print()
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

private:
    static void Heapify_bottom_to_top(vector<T> &arr, int n)
    {
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
    static void Heapify_top_to_bottom(vector<T> &arr, int n, int idx)
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
};

/*
How to use this library:
#include "Max_Heap_Library.cpp"
*/