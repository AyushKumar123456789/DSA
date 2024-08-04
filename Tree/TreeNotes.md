## Tree:

### Tree is DAG(Directed Acyclic Graph) with one root node.

### Tree Terminology:

- **Root Node**: The top node in a tree.
- **Parent Node**: A node directly connected to another node when moving away from the root.
- **Child Node**: A node directly connected to another node when moving towards the root.
- [**Tree Diameter**](/Tree/): The longest path between two nodes in a tree.
  - Algorithm to calculate the Diameter of a tree:
    - Select a random node and find the farthest node from it.
    - Then find the farthest node from the farthest node.
    - The distance between the two farthest nodes is the diameter of the tree.

## [Tree ReRooting](/Tree/CSES/Tree_Diameter.cpp)

It is a technique to solve the problem , For example we have a tree and we have to find the maximum sum of the path from every node to every other node in the tree.
So, Here we can use the tree ReRooting technique to solve this problem in O(n) time complexity , instead of solving for every node we solve for the one node considering it as the root and then just make the other node as root for calculating for that node in O(1) time complexity.

## Binary Lifting

It is a pre processing technique, In preprocessing, we initialize the ancestor[][] table, such that ancestor[i][j] stores the jth ancestor of node i.

- Initially, we set all the cells of ancestor[][] table = -1.
- Run a DFS to initialize the immediate parent, that is we initialize ancestor[i][0] for all the nodes.
- Now, we have initialized the first column of our ancestor table. For all the remaining columns, we can use the following recursive formula,

**ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1], when ancestor[i][j-1] != -1**

The idea is that we can reach (2^j)th ancestor of node i, by making 2 jumps of size (2^(j-1)), that is (2^j) = (2^(j-1)) + (2^(j-1)). After the first jump from node i, we will reach ancestor[i][j-1] and after the 2nd jump from node ancestor[i][j-1], we will reach ancestor[ancestor[i][j-1]][j-1]

Example :
So, to calculate 100th ancestor of Node X,
Move to 64th ancestor of X = ancestor[X][6] = A1
Then, to calculate the 36th ancestor of A1,
Move to the 32nd ancestor of A1 = ancestor[A1][5] = A2
Then, to calculate the 4th ancestor of A2,
Move to the 4th ancestor of A2 = ancestor[A2][2] = A3

### Applications of Binary Lifting:

- [**Finding the Kth ancestor of a node in a tree.**](/Tree/CSES/Company_Queries_I.cpp)

- [**Finding the LCA of two nodes in a tree.**](/Tree/CSES/Company_Queries_2.cpp)

Algorithm to find the LCA of two nodes in a tree using Binary Lifting:

- First, we find the level of both the nodes.
- Then, we bring both the nodes to the same level.
- Then, we start moving up from both the nodes simultaneously, until we find the LCA.

## Using LCA and Segement Tree in question [CSES/Counting_paths](/Tree/CSES/Counting_Paths.cpp)

**Approach**
See, we have to find the number of paths on which particular node comes in the tree. To do so, we can use the LCA and Segment Tree.

- First, Hme paths paths die hai, for example path a & b , we add 1 to a & add 1 to b and substract 1 to LCA of a & b now, since agar hm prefex array calculate krenge
  to LCA se upper bs ek bar minus one hoga pr hme do bar minus one krna hai , for both a and b, what we do is minus one to parent of lca of a and b.

## Euler Tour Technique

- It is a technique to convert a tree into an array. The array is called the Euler Tour of the tree.
  Then this array is converted into a segment tree to solve the queries in O(logn) time complexity.
  Problems Like :
- [**Subtree Queries**](/Tree/CSES/SubtreeQueries.cpp): Given a tree and Q queries, each query consists of a node, we have to find the sum of the subtree of that node and update the value of that node.
- [**Path Queries**](/Tree/CSES/PathQueries.cpp): Given a tree and Q queries, each query consists of two nodes, we have to calculate the sum of values on the path from the root to node s, and update the value of node s.

This Two problems can be solved using Euler Tour Technique. Storing the entry and exit time of the nodes the array which is used to find the position of nodes in the segment tree. To make the queries on segemtn tree.

For Understanding , Consider question 1:
Where we have to find the sum of the subtree of a node and update the value of that node.

- Create an euler tour array of the tree which contains every nodes twice.
- And also store the entry time and exit time of the nodes.
- Now, we can create a segment tree of the euler tour array.
- Now to find the sum of the subtree of a node s, we can find the sum of elements in segment tree from index entry[s] to exit[s].
- To update the value of node s, we can update the value of the segment tree at index entry[s] and exit[s].

## Heavy Light Decomposition(Heavy Topic , for later study)
