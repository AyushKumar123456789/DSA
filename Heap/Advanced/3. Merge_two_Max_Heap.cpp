// https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

#include <bits/stdc++.h>
using namespace std;

void Heapify(vector<int> &arr, int idx, int n)
{
    while (idx < n)
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

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[0] > b[0])
        {
            ans.push_back(a[0]);
            swap(a[0], a[n - i - 1]);
            Heapify(a, 0, n - i - 1);
            i++;
        }
        else
        {
            ans.push_back(b[0]);
            swap(b[0], b[m - j - 1]);
            Heapify(b, 0, m - j - 1);
            j++;
        }
    }

    while (i < n)
    {
        ans.push_back(a[0]);
        swap(a[0], a[n - i - 1]);
        Heapify(a, 0, n - i - 1);
        i++;
    }
    while (j < m)
    {
        ans.push_back(b[0]);
        swap(b[0], b[m - j - 1]);
        Heapify(b, 0, m - j - 1);
        j++;
    }
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    return ans;
}

int main()
{
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};
    int n = a.size();
    int m = b.size();
    vector<int> ans = mergeHeaps(a, b, n, m);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
Time Complexity : O(n+m) , where n is the size of the first heap and m is the size of the second heap.
Space Complexity : O(1)
*/