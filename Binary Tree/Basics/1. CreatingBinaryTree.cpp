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
        data = val;
        left = NULL;
        right = NULL;
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

void LevelOrderTraversal(Node *root)
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
        Node *current = q.front();
        if (current == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty()) // Queue is not empty
            {
                q.push(NULL);
            }
            continue;
        }

        cout << current->data << " ";
        if (current->left != NULL)
        {
            q.push(current->left);
        }
        if (current->right != NULL)
        {
            q.push(current->right);
        }
        q.pop();
    }
}

int main()
{
    Node *root = NULL;
    root = CreateBinaryTree(root);
    cout << "Level Order Traversal : " << endl;
    LevelOrderTraversal(root);
    cout << endl;
    return 0;
}
// Test Input : 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
// Output : 1 2 3 4 5 6 7
