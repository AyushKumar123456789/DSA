#include <bits/stdc++.h>
using namespace std;

int sum(int idx, vector<int> &BIT)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += BIT[idx];
        idx = idx - (idx & -idx);
    }
    return sum;
}

void update(int idx, int val, vector<int> &BIT)
{
    int n = BIT.size();
    while (idx < n)
    {
        BIT[idx] += val;
        idx += (idx & -idx);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;

    int maxi = *max_element(arr.begin(), arr.end());
    vector<int> BIT(maxi + 2, 0); // +2 to handle 1-based indexing

    long long inversion_count = 0;
    for (int i = 0; i < n; i++)
    {
        inversion_count += sum(maxi, BIT) - sum(arr[i], BIT);
        cout << "inversion_count: " << inversion_count << endl;
        update(arr[i], 1, BIT);
    }

    cout << "Number of inversions: " << inversion_count << endl;

    return 0;
}

// Time complexity of the above code is O(nlogn) where n is the size of the array.
// Space complexity is O(max(arr[i])) where arr[i] is the maximum element in the array.

// So to reduce space complexity we can use coordinate compression.
// Coordinate compression is a technique used to reduce the range of the values of the array.
// We can map the values of the array to a range of [1, n] where n is the number of distinct elements in the array.

/*
We can use map to store the mapping of the values of the array to the range [1, n].
Then we can replace the values of the array with the mapped values.
Then we can use the same code as above to calculate the number of inversions.

#include <bits/stdc++.h>
using namespace std;

int sum(int idx, vector<int> &BIT)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += BIT[idx];
        idx = idx - (idx & -idx);
    }
    return sum;
}

void update(int idx, int val, vector<int> &BIT)
{
    int n = BIT.size();
    while (idx < n)
    {
        BIT[idx] += val;
        idx += (idx & -idx);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;

    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    map<int, int> mp;
    int idx = 1;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(temp[i]) == mp.end())
            mp[temp[i]] = idx++;
    }
    for(int i = 0; i < n; i++)
        arr[i] = mp[arr[i]];
    }
    int maxi = n;
    vector<int> BIT(maxi + 2, 0); // +2 to handle 1-based indexing

    long long inversion_count = 0;

    for (int i = 0; i < n; i++)
    {
        inversion_count += sum(maxi, BIT) - sum(arr[i], BIT);
        update(arr[i], 1, BIT);
    }

    cout << "Number of inversions: " << inversion_count << endl;

    return 0;



*/