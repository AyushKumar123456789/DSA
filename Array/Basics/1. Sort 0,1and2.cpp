/*
Approach : Use Counting , Time Complexity: O(N) + O(N) (We have to traverse the array two times)
Approach 2 : 3 Pointers Approach, Time Complexity: O(N) , Space Complexity: O(1)
Logic Approach 2 : mid pura traverse krega or jo jis pointer k hai usko dedega , or while(mid<=h) -> equal mt bhulna because hoskta h , mid or h 0 pe ake mila ho to us 0 ko l pointer k pas phuchana hoga na
*/

#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &arr, int n)
{

    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
