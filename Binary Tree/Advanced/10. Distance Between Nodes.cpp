// https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

/*
Logic :
We first find the LCA of two nodes. Then we find the distance from LCA to two nodes.

Time Complexity: O(n), where n is the number of nodes in the binary tree.
Auxiliary Space: O(h), where h is the height of the binary tree.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

void level(Node *root, int a, int curr_level, int &Level)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == a)
    {
        Level = curr_level;
        return;
    }
    level(root->left, a, curr_level + 1, Level);
    level(root->right, a, curr_level + 1, Level);
}

/*
another code for level finding

    int level(Node* root,int a,int curr_level){
        if(root==NULL){
            return -1;
        }
        if(root->data==a){
            return curr_level;
        }
        int lft = level(root->left,a,curr_level+1);
        int rt = level(root->right,a,curr_level+1);
        if(lft==-1){
            return rt;
        }
        if(rt==-1){
            return lft;
        }
        return -1;
    }

    So write this for findDist

        int findDist(Node* root, int a, int b) {
        Node* lca = LCA(root,a,b);
        int levela = level(lca,a,0);
        int levelb = level(lca,b,0);
        return levela + levelb;
    }

*/
Node *LCA(Node *root, int a, int b)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == a || root->data == b)
    {
        return root;
    }
    Node *lft = LCA(root->left, a, b);
    Node *rt = LCA(root->right, a, b);
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

int findDist(Node *root, int a, int b)
{
    Node *lca = LCA(root, a, b);
    int levela = 0;
    level(lca, a, 0, levela);
    int levelb = 0;
    level(lca, b, 0, levelb);
    return levela + levelb;
}