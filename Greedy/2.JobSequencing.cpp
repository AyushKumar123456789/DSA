// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// Time Complexity: O(N^2)
// Space Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

pair<int, int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, compare);
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, arr[i].deadline);
    }
    vector<int> slot(maxDeadline, -1);
    int count = 0, profit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].deadline - 1; j >= 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = arr[i].id;
                count++;
                profit += arr[i].profit;
                break;
            }
        }
    }
    return {count, profit};
}

int main()
{
    int n;
    cin >> n;
    Job arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
    }
    pair<int, int> ans = JobScheduling(arr, n);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}

// Input
// 4
// 1 4 20
// 2 1 10
// 3 1 40
// 4 1 30

// Output
// 2 60