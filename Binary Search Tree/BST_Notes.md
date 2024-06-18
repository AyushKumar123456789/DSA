**\*\***[Basic Library](/Binary%20Search%20Tree/Basics/Basic_Bst_operation.cpp)

## Questions :

- ### [Basics](/Binary%20Search%20Tree/Basics/)
- ### [Advanced](/Binary%20Search%20Tree/Advanced/)

## Basics

- ### Binary Search Tree is a special type of binary tree which follows the following properties:

  - The left `subtree` of a node contains only nodes with keys lesser than the node’s key.
  - The right `subtree` of a node contains only nodes with keys greater than the node’s key.
  - The left and right `subtree` each must also be a binary search tree.

- ### [Insertion in BST:](/Binary%20Search%20Tree/Basics/BST_creation.cpp)

  - To insert a new node in BST, we need to follow the following steps:
    - Start from the root node and compare the key of the new node with the key of the current node.
    - If the key of the new node is less than the key of the current node, then move to the left subtree.
    - If the key of the new node is greater than the key of the current node, then move to the right subtree.
    - Repeat the above steps until we reach a leaf node.
    - Insert the new node at that leaf node.

- ### ❗Important Property❗ `Inorder Traversal in BST gives the elements in sorted order.` So, Inorder successor of a node is the next node in the inorder traversal of the tree and it is the smallest node in the right subtree of the node.

- ### [Deletion in BST:](/Binary%20Search%20Tree/Basics/3.%20Deletion._in_BST.cpp)

  - To delete a node from BST, we need to follow the following steps:

    - Start from the root node and compare the key of the node to be deleted with the key of the current node.
    - If the key of the node to be deleted is less than the key of the current node, then move to the left subtree.
    - If the key of the node to be deleted is greater than the key of the current node, then move to the right subtree.
    - If the key of the node to be deleted is equal to the key of the current node, then we have found the node to be deleted.

      - **There are three cases to consider while deleting a node from BST:**

      - If the node to be deleted is a leaf node, then simply delete the node.
      - If the node to be deleted has only one child, then copy the child to the node and delete the child.
      - If the node to be deleted has two children, then find the inorder successor or inorder predecessor of the node. Copy the value of the inorder successor or inorder predecessor to the node and delete the inorder successor or inorder predecessor.

- ### [Searching in BST:](/Binary%20Search%20Tree/Basics/2.%20Search_in_BST.cpp)

  - To search for a key in BST, we need to follow the following steps:
    - Start from the root node and compare the key of the current node with the key to be searched.
    - If the key of the current node is equal to the key to be searched, then we have found the key.
    - If the key of the current node is less than the key to be searched, then move to the right subtree.
    - If the key of the current node is greater than the key to be searched, then move to the left subtree.
    - Repeat the above steps until we reach a leaf node.
    - If we reach a leaf node, then the key is not present in the BST.

- `Static variables in a Function: When a variable is declared as static, space for it gets allocated for the lifetime of the program. Even if the function is called multiple times, space for the static variable is allocated only once and the value of the variable in the previous call gets carried through the next function call. `

## Moderate

- ### [Check if a binary tree is a BST or not:](/Binary%20Search%20Tree/Basics/5.%20Check_Tree_Is_BST.cpp)

  - To check if a binary tree is a BST or not, we need to follow the following steps:
    - Traverse the tree in inorder fashion and store the elements in an array.
    - Check if the array is sorted or not.
    - If the array is sorted, then the binary tree is a BST.

- ### [Creating a BST from a preorder traversal:](/Binary%20Search%20Tree/Advanced/1.Creating_Bst_from_preorder.cpp)

  - To create a BST from a preorder traversal, we need to follow the following steps:
    - Creat function which takes preorder traversal array and start and end index of the array.
    - Create a new node with the value of the first element of the preorder traversal array.
    - Find the index of the first element which is greater than the value of the first element of the preorder traversal array and let it be **i**.
    - Recursively call the function for the left and right subtree , for left start+1 and end=i-1 and for right start=i and end=end.

## [Balanced BST](/Binary%20Search%20Tree/Advanced/4.%20Balance_a_BST.cpp)

**A Balanced Binary Search Tree is a binary search tree in which the depth of the left and right subtree of any node differ by not more than 1.**
