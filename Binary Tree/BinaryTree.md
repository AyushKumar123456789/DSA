# Binary Tree

## Basics :

### Binary tree is non-linear data structure in which each node has at most two children, which are referred to as the left child and the right child , while Simple tree can have any number of children.

- [Node: A single element in a tree.](/Binary%20Tree/Basics/1.%20CreatingBinaryTree.cpp)

- Root: The topmost node in a tree.

- Parent: A node that has child nodes.

- Child: A node that has a parent node.

- Leaf: A node that has no children.

- Sibling: Nodes that share the same parent.

- Ancestor: A node that is on the path from the root to a given node.

- Descendant: A node that is on the path from a given node to a leaf.

- Depth: The number of edges on the path from the root to a given node.

- [Height: The number of Nodes on the longest path from a given node to a leaf.](/Binary%20Tree/Basics/3.%20Height.cpp)

- Level: The set of all nodes at a given depth.

- Subtree: A tree that is a descendant of a given node.

- [Diameter: The number of nodes on the longest path between two leaves in the tree.](/Binary%20Tree/Basics/4.%20Diameter.cpp)

- [Balanced Tree: A tree is balanced if the height of the left and right subtrees of every node differ by at most 1.](/Binary%20Tree/Basics/12.%20Balance%20Check.cpp)

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

- ### [1. Inorder Traversal : In this traversal, the nodes are recursively visited in this order: left, root, right.](/Binary%20Tree/Basics/5%20InorderTraversal.cpp)

  - Example : Inorder traversal of 1 2 -1 4 -1 -1 3 -1 -1 is 4 2 1 3 is 4 2 1 3

- ### [2. Preorder Traversal : In this traversal, the nodes are recursively visited in this order: root, left, right.](/Binary%20Tree/Basics/6.%20Preorder.cpp)

  - Example : Preorder traversal of 1 2 -1 4 -1 -1 3 -1 -1 is 1 2 4 3

- ### [3. Postorder Traversal : In this traversal, the nodes are recursively visited in this order: left, right, root.](/Binary%20Tree/Basics/7.%20PostOrder.cpp)

  - Example : Postorder traversal of 1 2 -1 4 -1 -1 3 -1 -1 is 4 2 3 1

  `Important : Postorder traversal is used to delete the tree , AND PostOrder Traversal is Reverse of PreOrder Traversal with only difference that right child is visited/appended before left child.`
