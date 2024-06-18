// https://www.geeksforgeeks.org/problems/minimum-swap-required-to-convert-binary-tree-to-binary-search-tree/0

/*
Uses Similar concept as the problem convert BT to BST in BST FILE

Logic:
1. Do inorder traversal of the tree and store the elements in an array.
2. Sort the array.
3. Now, we need to find the minimum number of swaps required to convert the array to a sorted array.
*/

int left(int idx, int n)
{
    if (2 * idx + 1 >= n)
    {
        return -1;
    }
    return 2 * idx + 1;
}

int right(int idx, int n)
{
    if (2 * idx + 2 >= n)
    {
        return -1;
    }
    return 2 * idx + 2;
}

void Inorder(const vector<int> &A, int idx, int n, vector<int> &arr)
{
    if (idx >= n || idx == -1)
    {
        return;
    }
    Inorder(A, left(idx, n), n, arr);
    arr.push_back(A[idx]);
    Inorder(A, right(idx, n), n, arr);
}

int minSwaps(vector<int> &A, int n)
{
    vector<int> arr;
    Inorder(A, 0, n, arr);
    unordered_map<int, int> idx;
    for (int i = 0; i < n; i++)
    {

        idx[arr[i]] = i;
    }

    vector<int> temp(arr.begin(), arr.end());
    sort(temp.begin(), temp.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != temp[i])
        {
            ans++;
            int idx1 = idx[arr[i]];
            int idx2 = idx[temp[i]];
            int a = arr[i];
            int b = temp[i];
            swap(arr[i], arr[idx[temp[i]]]);
            idx[a] = idx2;
            idx[b] = idx1;
        }
    }
    return ans;