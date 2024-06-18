/*
3 Type of questions :

1. Find number of paths whose sum is k.  |____ Path  starts from any node and ends in any node but you can move only downward direction.
2. print all paths whose sum is k .      |

3. Print all the paths from root, with a specified sum in Binary tree.

*/

// https://www.geeksforgeeks.org/problems/k-sum-paths/1

/*
Time Complexity : O(N)
Space Complexity : O(N)
*/

void f(Node *root, int &cnt, int k, std::unordered_map<int, int> &arr, int curr_sum)
{
    if (root == NULL)
    {
        return;
    }

    curr_sum += root->data;

    if (curr_sum == k)
    {
        cnt++;
    }

    cnt += arr[curr_sum - k];

    arr[curr_sum]++;

    f(root->left, cnt, k, arr, curr_sum);
    f(root->right, cnt, k, arr, curr_sum);

    arr[curr_sum]--;
}

int sumK(Node *root, int k)
{
    int cnt = 0;
    std::unordered_map<int, int> arr;
    f(root, cnt, k, arr, 0);
    return cnt;
}

/*
Print all k sum path :

https://www.geeksforgeeks.org/print-k-sum-paths-binary-tree/
*/

/*
Print all the paths from root, with a specified sum in Binary tree

https://www.geeksforgeeks.org/print-paths-root-specified-sum-binary-tree/

*/