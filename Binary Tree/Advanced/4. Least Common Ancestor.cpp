// https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

/*
Little tricky and need visulaization :

Explanation :
1. Do Simple left , right traversal & if found NULL return NULL, if found any of node which we are searching for just return the that node imidiately without going down
in search of other node , by considering this migth be the solution.
2. So, if left call return NULL , then right might be the answer.
3. & If right return NULL, then left might be answer .
4. But whenever in future we found both left and right not null , we return that node , considering him as LCA

*/

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

struct Node
{
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

Node *create_tree(Node *root)
{
    int n;
    cout << "Enter value : ";
    cin >> n;
    if (n == -1)
    {
        return NULL;
    }
    Node *temp = new Node(n);
    cout << " Enter Left Node : ";
    temp->left = create_tree(temp->left);
    cout << "Enter Right Node : ";
    temp->right = create_tree(temp->right);
    root = temp;
    return root;
}

/*
LCA Code is VERY Small
*/

Node *lca(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node *lft = lca(root->left, n1, n2);
    Node *rt = lca(root->right, n1, n2);
    if (lft == NULL)
    {
        return rt;
    }
    if (rt == NULL)
    {
        return lft;
    }
    return root;
}

int main()
{
    Node *root;
    root = create_tree(root);
    cout << "enter LCA n1 and n2 ";
    int n1, n2;
    cin >> n1 >> n2;
    cout << " LCA : " << endl;
    cout << lca(root, n1, n2)->data << endl; // If lca not exist means n1 or n2 m se koi farzi h to NULL return hoga usko alga se check kr lena
}