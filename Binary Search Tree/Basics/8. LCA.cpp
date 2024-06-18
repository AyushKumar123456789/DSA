#include "Basic_Bst_operation.cpp"

/*
Logic :
1. If both n1 and n2 are smaller than the root, then LCA lies in the left.
2. If both n1 and n2 are greater than the root, then LCA lies in the right.
3. Else, the root is LCA. (So, First node which lies between n1 and n2 is the LCA)


*/

/*
Itrerative approach:
Time complexity: O(h) where h is the height of the tree.
space complexity: O(1)
*/

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    Node *curr = root;
    while (!(curr->data <= max(n1, n2) && curr->data >= min(n1, n2)))
    {
        if (curr->data > n1 && curr->data > n2)
        {
            curr = curr->left;
        }
        else if (curr->data < n1 && curr->data < n2)
        {
            curr = curr->right;
        }
    }
    return curr;
}

/*
Recursive approach:

Time complexity: O(h) where h is the height of the tree.
space complexity: O(h) where h is the height of the tree.
*/

Node *LCA_recursive(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data > n1 && root->data > n2)
    {
        return LCA(root->left, n1, n2);
    }
    else if (root->data < n1 && root->data < n2)
    {
        return LCA(root->right, n1, n2);
    }
    else
    {
        return root;
    }
    return root;
}