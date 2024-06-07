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

void postOrder_Recursive(Node *root)
{
    if (root == NULL)
        return;
    postOrder_Recursive(root->left);
    postOrder_Recursive(root->right);
    cout << root->data << " ";
}

/*
Iterative PostOrder Traversal: It is little bit tricky as compared to PreOrder and InOrder Traversal.
We will use two stacks to solve this problem.
1. We will push the root node into the stack1.
2. We will pop the top element from stack1 and push it into stack2.
3. Then we will push the left and right child of the popped element into stack1.
4. We will repeat the above steps until stack1 is empty.
5. Finally we will print the elements of stack2.

!!!!!!!!!!IMPORTANT!!!!!!!!!!!!!!

PostOrder Traversal is the reverse of PreOrder Traversal with the only difference that we have to put the right child first and then the left child.


Time Complexity: O(n)
Space Complexity: O(n)

*/

void postOrder_Iterative(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);
    while (!s1.empty())
    {
        Node *temp = s1.top();
        s1.pop();
        s2.push(temp);
        if (temp->left)
            s1.push(temp->left);
        if (temp->right)
            s1.push(temp->right);
    }
    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    postOrder_Recursive(root);
    cout << endl;
    postOrder_Iterative(root);
    return 0;
}
