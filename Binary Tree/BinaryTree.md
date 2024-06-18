# Binary Tree

### QUETIONS :

- #### [Basic Questions](/Binary%20Tree/Basics/)
- #### [Advanced Questions](/Binary%20Tree/Advanced/)

## Basics :

### Binary tree is non-linear data structure in which each node has at most two children, which are referred to as the left child and the right child , while Simple tree can have any number of children.

- [Node](/Binary%20Tree/Basics/1.%20CreatingBinaryTree.cpp): A single element in a tree.

- Root: The topmost node in a tree.

- Parent: A node that has child nodes.

- Child: A node that has a parent node.

- Leaf: A node that has no children.

- Sibling: Nodes that share the same parent.

- Ancestor: A node that is on the path from the root to a given node.
  - [LCA : Least Common Ancestor](/Binary%20Tree/Advanced/4.%20Least%20Common%20Ancestor.cpp)
  - [Kth ancestor](/Binary%20Tree/Advanced/6.%20Kth%20ancestor.cpp)
- Descendant: A node that is on the path from a given node to a leaf.

- Depth: The number of edges on the path from the root to a given node.

- [Height](/Binary%20Tree/Basics/3.%20Height.cpp)
  : The number of Nodes on the longest path from a given node to a leaf.
- Level: The set of all nodes at a given depth.

- Subtree: A tree that is a descendant of a given node.

- [Diameter](/Binary%20Tree/Basics/4.%20Diameter.cpp): The number of nodes on the longest path between two leaves in the tree.

- [Balanced Tree](/Binary%20Tree/Basics/12.%20Balance%20Check.cpp)
  : A tree is balanced if the height of the left and right subtrees of every node differ by at most 1.
- [Isomorphic ](/Binary%20Tree/Advanced/9.%20Isomorphic%20Tree.cpp): Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.

### Creating a Binary Tree

```cpp
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* CreateBinaryTree(Node* root){
    int data;
    cout<<"Enter data : ";
    cin>>data;
    if(data == -1){
        return NULL;
    }
    root = new Node(data);
    cout<<"Enter left child of "<<data<<" : ";
    root->left = CreateBinaryTree(root->left);
    cout<<"Enter right child of "<<data<<" : ";
    root->right = CreateBinaryTree(root->right);
    return root;
}

void LevelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* current = q.front();
        if(current == NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        cout<<current->data<<" ";
        if(current->left != NULL){
            q.push(current->left);
        }
        if(current->right != NULL){
            q.push(current->right);
        }
        q.pop();
    }
}

int main(){
    Node* root = NULL;
    root = CreateBinaryTree(root);
    cout<<endl;
    LevelOrderTraversal(root);
    return 0;
}


```

## Traverse a Binary Tree :

- ### [1. Inorder Traversal ](/Binary%20Tree/Basics/5%20InorderTraversal.cpp): In this traversal, the nodes are recursively visited in this order: left, root, right.

  - Example : Inorder traversal of 1 2 -1 4 -1 -1 3 -1 -1 is 4 2 1 3 is 4 2 1 3

- ### [2. Preorder Traversal](/Binary%20Tree/Basics/6.%20Preorder.cpp) : In this traversal, the nodes are recursively visited in this order: root, left, right.

  - Example : Preorder traversal of 1 2 -1 4 -1 -1 3 -1 -1 is 1 2 4 3

- ### [3. Postorder Traversal](/Binary%20Tree/Basics/7.%20PostOrder.cpp) : In this traversal, the nodes are recursively visited in this order: left, right, root.

  - Example : Postorder traversal of 1 2 -1 4 -1 -1 3 -1 -1 is 4 2 3 1

  `Important : Postorder traversal is used to delete the tree , AND PostOrder Traversal is Reverse of PreOrder Traversal with only difference that right child is visited/appended before left child.`

## Constracting Binary Tree From Other Traversals.

- ### [From Inorder and Preorder Traversal.](/Binary%20Tree/Advanced/7.%20BT%20Creation%20From%20Inorder%20&%20Preorder.cpp)

- ### [From Inorder and Postorder Traversal.](/Binary%20Tree/Advanced/8.%20BT%20Creation%20From%20Inorder%20and%20PostOrder.cpp)

## Types Of Binary Tree :

1. ### Full Binary Tree : A Binary Tree is full if every node has 0 or 2 children.

2. ### Complete Binary Tree : A Binary Tree is complete Binary Tree if all levels are completely filled except possibly the last level and the last level has all keys as left as possible.

3. ### Perfect Binary Tree : A Binary tree is Perfect Binary Tree in which all internal nodes have two children and all leaves are at the same level.

4. ### Balanced Binary Tree : A binary tree is balanced if the height of the tree is O(Log n) where n is the number of nodes.
