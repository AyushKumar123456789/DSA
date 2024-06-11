
/*
Extra Space Use Hoga , Time Complexity: O(N) , Space Complexity: O(N)

*/

void segregateElements(int arr[], int n)
{
    int temp[n];
    int cnt_n = 0;
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            temp[idx] = (arr[i]);
            idx++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            temp[idx] = (arr[i]);
            idx++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}