// https://www.geeksforgeeks.org/kth-ancestor-node-binary-tree-set-2/

/*
Time Complexity: O(n), where n is the number of nodes in the binary tree.

Auxiliary Space: O(h) where h is the height of binary tree due to recursion call.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

// recursive function to calculate Kth ancestor
Node *kthAncestorDFS(Node *root, int node, int &k)
{
    // Base case
    if (!root)
        return NULL;

    if (root->data == node ||
        (kthAncestorDFS(root->left, node, k)) ||
        (kthAncestorDFS(root->right, node, k)))
    {
        if (k > 0)
            k--;

        else if (k == 0)
        {
            // print the kth ancestor
            cout << "Kth ancestor is: " << root->data;

            // return NULL to stop further backtracking
            return NULL;
        }

        // return current node to previous call
        return root;
    }
}

// Utility function to create a new tree node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int k = 2;
    int node = 5;

    // print kth ancestor of given node
    Node *parent = kthAncestorDFS(root, node, k);

    // check if parent is not NULL, it means
    // there is no Kth ancestor of the node
    if (parent)
        cout << "-1";

    return 0;
}
