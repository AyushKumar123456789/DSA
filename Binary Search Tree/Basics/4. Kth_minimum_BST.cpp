#include "Basic_Bst_operation.cpp"

/*
Logic:
1. Traverse the left subtree and this code run from bottom to top.
2. When k becomes 0, return the data of the node.
3. Traverse the right subtree.
4. If the right subtree returns -1, return -1.
5. If the right subtree returns a value, return that value.
6. If k becomes 0, return the data of the node.
7. If k is not 0, decrement k and return -1.


 The time complexity of this code is O(h) where h is the height of the tree and h=log(n) in the case of a balanced BST and h=n in the case of a skewed BST.
 The space complexity of this code is O(h) for the recursive call stack.
*/

int kthSmallest(Node *root, int &k)
{
    if (root == NULL)
    {
        return -1;
    }
    int left = kthSmallest(root->left, k);
    if (left != -1)
    {
        return left;
    }
    k--;
    if (k == 0)
    {
        return root->data;
    }
    return kthSmallest(root->right, k);
}

/*
Iterative approach:

Because it is from bottom to top, iterative approach not reduces the space complexity.
*/

int kthSmallest_iterative(Node *root, int k)
{
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        k--;
        if (k == 0)
        {
            return curr->data;
        }
        curr = curr->right;
    }
    return -1;
}

int kthLargest(Node *root, int &k)
{
    if (root == NULL)
    {
        return -1;
    }
    int rt = kthLargest(root->right, k);
    if (rt != -1)
    {
        return rt;
    }
    k--;
    if (k == 0)
    {
        return root->data;
    }
    return kthLargest(root->left, k);
}

int main()
{
    Node *root = createBst();
    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    int ans = kthSmallest(root, k);
    if (ans == -1)
    {
        cout << "The value of k is greater than the number of nodes in the BST" << endl;
    }
    else
    {
        cout << "The kth smallest element in the BST is: " << ans << endl;
    }
    return 0;
}