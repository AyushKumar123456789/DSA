// https://www.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right, *next;
    Node(int val)
    {
        data = val;
        left = right = next = NULL;
    }
};

void populateNext(Node *root)
{
    static Node *prev = NULL;
    /*
        Static variable to store the previous node is necessary as we need to keep track of the previous
        node in the inorder traversal and static keyword is used to retain the value of the variable between the function calls.
    */

    /*
        Static variables in a Function: When a variable is declared as static, space for it gets allocated for the lifetime of the program. Even
        if the function is called multiple times, space for the static variable is allocated only once and the value of the variable in the previous call
        gets carried through the next function call.
    */
    if (root)
    {
        populateNext(root->left);
        if (prev)
        {
            prev->next = root;
        }
        prev = root;
        populateNext(root->right);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);
    root->left->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(15);

    populateNext(root);

    Node *ptr = root->left->left;
    while (ptr)
    {
        cout << "Next of " << ptr->data << " is ";
        if (ptr->next)
            cout << ptr->next->data << endl;
        else
            cout << "-1" << endl;
        ptr = ptr->next;
    }
    return 0;
}