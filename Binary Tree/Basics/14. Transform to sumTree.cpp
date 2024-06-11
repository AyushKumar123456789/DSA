// https://www.geeksforgeeks.org/problems/transform-to-sum-tree/1

/*
Easy : Node is sum of left and right subtree not the left and right node , So , to get node value add left and rght node value and return left + right + node value
*/

int f(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lft = f(root->left);
    int rt = f(root->right);
    int temp = lft + rt + root->data;
    root->data = lft + rt;
    return temp;
}

void toSumTree(Node *node)
{
    f(node);
}

/*
Similar Question Check Binary Tree is Sumtree or not ,
Don't forget the if(root==NULL)return 0;
*/

long long f(Node *root, bool &check)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    long long lt = f(root->left, check);
    long long rt = f(root->right, check);
    if (lt + rt != root->data)
    {
        check = 0;
    }
    return lt + rt + root->data;
}

bool isSumTree(Node *root)
{
    if (root == NULL)
        return 1;
    bool check = 1;
    f(root, check);
    return check;
}