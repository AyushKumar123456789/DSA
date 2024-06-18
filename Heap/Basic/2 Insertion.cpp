#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
class Max_Heap
{
public:
    static void insert(int val)
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
    static void Heapify(int idx)
    {
        while (1)
        {
            int largest = idx;
            int l = 2 * idx + 1;
            int r = 2 * idx + 2;
            if (l < arr.size() && arr[l] > arr[largest])
            {
                largest = l;
            }
            if (r < arr.size() && arr[r] > arr[largest])
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
    static void Delete()
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
            Max_Heap::Heapify(0);
        }
    }
    static void print()
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        Max_Heap::insert(a);
        Max_Heap::print();
    }
}
