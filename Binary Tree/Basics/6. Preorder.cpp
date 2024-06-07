#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;
    Node(int val)
    {
        data = val;
    }
};

Node *Create_Node(Node *root)
{
    int data;
    cout << "Enter Data : ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    cout << "Enter Left Node  : " << endl;
    root->left = Create_Node(root->left);
    cout << "Enter Right Node : " << endl;
    root->right = Create_Node(root->right);
    return root;
}

void preorder_recursive(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << (root->data) << " ";
    preorder_recursive(root->left);
    preorder_recursive(root->right);
}

void preorder_iterative(Node *root)
{
    Node *current = root;
    stack<Node *> st;
    while (!st.empty() || current != NULL)
    {
        while (current != NULL)
        {
            cout << (current->data) << " ";
            st.push(current);
            current = current->left;
        }
        Node *temp = st.top();
        st.pop();
        if (temp->right != NULL)
        {
            current = temp->right;
        }
    }
}

// Other way to write the above code

void preorder_iterative_2(Node *root)
{
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();
        cout << temp->data << " ";
        if (temp->right)
        {
            st.push(temp->right);
        }
        if (temp->left)
        {
            st.push(temp->left);
        }
    }
}

int main()
{
    Node *root = NULL;
    root = Create_Node(root);
    cout << "PreOrder Traversal : " << endl;
    preorder_iterative(root);
    return 0;
}