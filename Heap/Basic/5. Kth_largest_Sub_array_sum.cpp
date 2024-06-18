// https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

/*
Time complexity: O(n^2 log k)
Auxiliary Space: O(k)

*/

#include <bits/stdc++.h>
#include "Heap_Library.cpp" // Include the corrected heap library
using namespace std;

int kthLargest(vector<int> &Arr, int N, int K)
{
    My_priority_queue<int> pq; // Use min-heap
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += Arr[j];
            pq.push(sum);
            if (pq.size() > K)
            {
                pq.pop();
            }
        }
    }
    return pq.top();
}

int main()
{
    vector<int> Arr = {10, -10, 20, -40};
    int N = Arr.size();
    int K = 6;
    cout << kthLargest(Arr, N, K) << endl;
    return 0;
}
