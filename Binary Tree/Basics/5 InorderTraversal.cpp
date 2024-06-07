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

Node *CreateTree(Node *root)
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
    root->left = CreateTree(root->left);
    cout << "Enter right child of " << data << " : ";
    root->right = CreateTree(root->right);
    return root;
}

void Inorder_Recursive(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder_Recursive(root->left);
    cout << root->data << " ";
    Inorder_Recursive(root->right);
}

void Inorder_Iterative(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> st;
    Node *current = root;
    while (current != NULL || !st.empty())
    {
        while (current != NULL)
        {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

int main()
{
    Node *root = NULL;
    root = CreateTree(root);
    cout << "Inorder Traversal (Recursive) : ";
    Inorder_Recursive(root);
    cout << endl;
    cout << "Inorder Traversal (Iterative) : ";
    Inorder_Iterative(root);
    return 0;
}