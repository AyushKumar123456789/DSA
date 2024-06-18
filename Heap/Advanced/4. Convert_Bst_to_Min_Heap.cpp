// https://www.geeksforgeeks.org/convert-bst-min-heap/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        this->data = val;
        this->left = this->right = NULL;
    }
};

void inorderTraversal(Node *root, vector<int> &arr)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left, arr);
    arr.push_back(root->data);
    inorderTraversal(root->right, arr);
}

void BSTToMinHeap(Node *root, vector<int> arr, int *i)
{
    if (root == NULL)
        return;
    root->data = arr[++*i];
    BSTToMinHeap(root->left, arr, i);
    BSTToMinHeap(root->right, arr, i);
}

void convertToMinHeapUtil(Node *root)
{
    vector<int> arr;
    int i = -1;
    inorderTraversal(root, arr);
    BSTToMinHeap(root, arr, &i);
}

void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Insertion in BST

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

Node *createBst()
{
    cout << "Enter the number of nodes you want to insert in the BST: ";
    int n;
    cin >> n;
    Node *root = NULL;
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    return root;
}
// Level order traversal

void levelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            cout << endl;
        }
    }
}

int main()
{
    Node *root = createBst();
    cout << "Level order traversal of the BST: " << endl;
    levelOrder(root);
    convertToMinHeapUtil(root);
    cout << "Level order traversal of the Min Heap: " << endl;
    levelOrder(root);
    return 0;
}
// Test case:
//  5
//  4 2 6 1 3
//  Output: 1 2 4 3 6