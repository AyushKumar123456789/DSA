// https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

#include "Heap_Library.cpp"
using namespace std;

/*
Steps:
1. Create a min heap of size K and insert the first element of all the K arrays.
2. Pop the top element of the heap and insert the next element from the same array to which the top element belongs.
3. Repeat the above step until all the elements of the arrays are not inserted into the heap.
4. Finally, the heap will have all the elements of the K arrays in a sorted order.

Time Complexity: O(N * K * log K)
Space Complexity: O(K)

Merge K sorted arrays

*/

struct Triplet
{
    int val, ap, vp;
    Triplet(int v, int a, int p)
    {
        val = v;
        ap = a;
        vp = p;
    }
};

struct Compare
{
    bool operator()(Triplet &a, Triplet &b)
    {
        return a.val > b.val;
    }
};

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    vector<int> output;
    My_pritority_queue<Triplet, vector<Triplet>, Compare> pq;
    for (int i = 0; i < K; i++)
    {
        pq.push(Triplet(arr[i][0], i, 0));
    }
    while (!pq.empty())
    {
        Triplet curr = pq.top();
        pq.pop();
        output.push_back(curr.val);
        int ap = curr.ap;
        int vp = curr.vp;
        if (vp + 1 < K)
        {
            pq.push(Triplet(arr[ap][vp + 1], ap, vp + 1));
        }
    }
    return output;
}

int main()
{
    vector<vector<int>> arr = {{2, 6, 12, 34},
                               {1, 9, 20, 1000},
                               {23, 34, 90, 2000}};
    int K = arr.size();
    vector<int> output = mergeKArrays(arr, K);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    return 0;
}
