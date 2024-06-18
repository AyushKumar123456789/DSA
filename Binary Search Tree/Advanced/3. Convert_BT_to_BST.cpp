// https://www.geeksforgeeks.org/problems/binary-tree-to-bst/1

/*
Logic:
Use Inorder Traversla and Sorting of array.
1. Traverse the tree in inorder fashion and store the data in an array.
2. Sort the array.
3. Traverse the tree in inorder fashion and replace the data with the array elements.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node *createBT()
{
    cout << "Enter node data: ";
    int x;
    cin >> x;
    if (x == -1)
        return NULL;
    Node *root = new Node(x);
    cout << "Enter left of " << x << endl;
    root->left = createBT();
    cout << "Enter right of " << x << endl;
    root->right = createBT();
    return root;
}

void Inorder(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left, arr);
    arr.push_back(root->data);
    Inorder(root->right, arr);
}

void Inorder_put(Node *root, vector<int> &arr, int &idx)
{
    if (root == NULL)
    {
        return;
    }
    Inorder_put(root->left, arr, idx);
    root->data = arr[idx++];
    Inorder_put(root->right, arr, idx);
}

Node *binaryTreeToBST(Node *root)
{

    vector<int> arr;
    Inorder(root, arr);
    sort(arr.begin(), arr.end());
    int idx = 0;
    Inorder_put(root, arr, idx);
    return root;
}

int main()
{
    Node *root = createBT();
    root = binaryTreeToBST(root);

    return 0;
}