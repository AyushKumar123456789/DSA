
/*
Question : Given weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
            In Fractional Knapsack, we can break items for maximizing the total value of knapsack. This problem in which we can break an item is also called the fractional knapsack problem.
            The idea of the greedy algorithm is to calculate the ratio value/weight for each item and sort the item on basis of this ratio. Then take the item with the highest ratio and add them until we can’t add the next item as a whole and at the end add the next item as much as we can. Which will always be the optimal solution to this problem.
            A simple code for Fractional Knapsack is given below.

Approach :
1.Find the ratio value/weight for each item.
2.Sort all items by this ratio.
3.Take the item with the highest ratio and add them until we can’t add the next item as a whole.
4.Add the next item as much as we can.
5.Print the maximum value of the knapsack.


*/

#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
    return (p1.first * 1.0 / p1.second) > (p2.first * 1.0 / p2.second);
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), comp);
    int W;
    cin >> W;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].second <= W)
        {
            ans += arr[i].first;
            W -= arr[i].second;
        }
        else
        {
            ans += arr[i].first * W * 1.0 / arr[i].second;
            break;
        }
    }
    cout << ans << endl;
}