#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        this->data = x;
        left = right = NULL;
    }
};

// Inorder traversal to store nodes in a vector
void inorder(Node *root, vector<Node *> &v)
{
    if (root == NULL)
        return;
    inorder(root->left, v);
    v.push_back(root);
    inorder(root->right, v);
}

// Flattening using vector and inorder traversal
Node *flatten(Node *root)
{
    if (root == NULL)
        return NULL;
    vector<Node *> v;
    inorder(root, v);
    for (int i = 0; i < v.size() - 1; i++)
    {
        v[i]->left = NULL;
        v[i]->right = v[i + 1];
    }
    v[v.size() - 1]->left = NULL;
    v[v.size() - 1]->right = NULL;
    return v[0];
}

// Helper function to recursively flatten the tree

void flattenRec(Node *root, Node *&prev)
{
    if (root == NULL)
        return;
    flattenRec(root->left, prev);
    root->right = prev;
    root->left = NULL;
    prev = root;
    flattenRec(root->right, prev);
}
// Flattening using recursion
Node *flatten2(Node *root)
{
    Node *prev = NULL;
    Node *small = root;
    while (small->left != NULL)
    {
        small = small->left;
    }
    flattenRec(root, prev);
    return small;
}

int main()
{
    // Creating a sample BST
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(8);
    root->left->left->left = new Node(1);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(9);

    // Flattening using vector method
    Node *head = flatten(root);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;

    // Resetting the BST
    Node *root2 = new Node(6);
    root2->left = new Node(5);
    root2->left = new Node(4);
    root2->left->left = new Node(3);
    root2->left->left->left = new Node(2);
    root2->left->left->left->left = new Node(1);
    // Flattening using recursion method
    root2 = flatten2(root2);
    while (root2 != NULL)
    {
        cout << root2->data << " ";
        root2 = root2->right;
    }
    cout << endl;

    return 0;
}
