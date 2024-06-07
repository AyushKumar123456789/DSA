/*
Here Height is defined as the number of Nodes in the longest path from the root to a leaf node.
IF Height is defined as number of edges in the longest path from the root to a leaf node then the code will be:
Just subtract 1 from the height of the tree.
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;
    Node(int data)
    {
        this->data = data;
    }
};

Node *CreateBinaryTree(Node *root)
{
    int data;
    cout << "Enter data : ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    cout << "Enter left child of " << data << " : ";
    root->left = CreateBinaryTree(root->left);
    cout << "Enter right child of " << data << " : ";
    root->right = CreateBinaryTree(root->right);
    return root;
}

int height(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int ans = 0;
    ans = max(ans, 1 + height(node->left));
    ans = max(ans, 1 + height(node->right));
    return ans;
}

int main()
{
    Node *root = NULL;
    root = CreateBinaryTree(root);
    cout << endl;
    cout << "Height of the tree is : " << height(root);
    return 0;
}

// Test case : 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
// Output : 3