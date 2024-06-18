#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

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
    cout << "Level order traversal of the BST is: " << endl;
    levelOrder(root);
    return 0;
}
