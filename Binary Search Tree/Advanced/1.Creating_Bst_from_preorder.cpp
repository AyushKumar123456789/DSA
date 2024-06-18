#include "Basic_Bst_operation.cpp"
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

/*
Time Complexity: O(n^2) because we are visiting every node exactly once.
Space Complexity: O(n) because we are using the recursion stack.

*/

Node *preOrder(int pre[], int start, int end)
{
    if (start > end)
        return NULL;
    Node *root = new Node(pre[start]);
    int i;
    for (i = start; i <= end; i++)
    {
        if (pre[i] > root->data)
            break;
    }
    root->left = preOrder(pre, start + 1, i - 1);
    root->right = preOrder(pre, i, end);
    return root;
}

Node *constructTree(int pre[], int size)
{
    return preOrder(pre, 0, size - 1);
}

/*
Approach 2:

Range approach , Going to left change upper limit and going to right change lower limit

Time Complexity : O(N)
Space complexity : O(H)
*/

Node *BST_from_preorder(vector<int> &pre, int mini, int maxi, int &idx)
{

    if (idx >= pre.size())
        return NULL;
    if (pre[idx] < maxi && pre[idx] > mini)
    {
        Node *temp = new Node(pre[idx++]);
        int temp_mini_maxi = pre[idx - 1];
        temp->left = BST_from_preorder(pre, mini, temp_mini_maxi, idx);
        temp->right = BST_from_preorder(pre, temp_mini_maxi, maxi, idx);
        return temp;
    }
    return NULL;
}

int main()
{
    vector<int> pre = {10, 5, 1, 7, 40, 50};

    // Node *root = constructTree(pre, size);
    int idx = 0;
    Node *root = BST_from_preorder(pre, -100000, 100000, idx);
    levelOrder(root);
    return 0;
}