// https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree/

/*
Logic : Read above aritcal

Sperate traversal for left, bottam and right boundary.

!!!!!!! Some IMPORTANT :  left_node and right_node function dont push root node, root node is pushed at the begining if it is not going to pushed be bottom function
*/

bool leaf(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return 0;
}

void left_node(Node *root, vector<int> &ans)
{
    Node *curr = root->left;
    while (curr)
    {
        if (leaf(curr))
            return;
        ans.push_back(curr->data);
        if (curr->left)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}

void right_node(Node *root, vector<int> &ans)
{
    Node *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (leaf(curr))
            break;
        temp.push_back(curr->data);
        if (curr->right)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        ans.push_back(temp[i]);
    }
}

void bottom(Node *root, vector<int> &ans)
{
    if (leaf(root))
    {
        ans.push_back(root->data);
    }
    if (root->left)
    {
        bottom(root->left, ans);
    }
    if (root->right)
    {
        bottom(root->right, ans);
    }
}

vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    if (!leaf(root))
    {
        ans.push_back(root->data);
    }
    left_node(root, ans);
    bottom(root, ans);
    right_node(root, ans);
    return ans;
}