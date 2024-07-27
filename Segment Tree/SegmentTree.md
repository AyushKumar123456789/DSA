## Segment Tree

### 1. Introduction

A segment tree is a data structure that allows answering range queries over an array effectively, This include finding the sum of consecutive array elements a[l…r], or finding the minimum element in a such a range in O(log n) time. A segment tree for a given array A[0, …, n-1] is a binary tree where each node contains a pair (l, r) such that 0 ≤ l ≤ r < n. The root of the tree contains the pair (0, n-1), and for each node (l, r) of the tree, the left child of (l, r) contains the pair (l, m), where m = (l+r)/2, and the right child contains the pair (m+1, r). Leaf nodes contain a single element A[i] such that l = r = i.

### 2. Construction

The segment tree for array A[0, …, n-1] is a binary tree in which each node contains aggregate information (min, max, sum, etc.) for a subrange A[i, …, j] of the array, as its left and right child hold information for range A[i, …, m] and A[m+1, …, j] respectively where m = (i+j)/2.

```cpp
void build(int id, int l, int r) {
    if (l == r) {
        // Leaf node will have a single element
        tree[id] = A[l];
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

int query(int id, int l, int r, int x, int y) {
    //if total overlap return the value
    if (x <= l && r <= y) {
        return tree[id];
    }
    //if no overlap return 0
    if (r < x || y < l) {
        return 0;
    }
    int m = (l + r) / 2;
    //if partial overlap go down
    return query(id * 2, l, m, x, y) + query(id * 2 + 1, m + 1, r, x, y);
}

void update(int id, int l, int r, int pos, int val) {
    if (l == r) {
        tree[id] = val;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) {
        update(id * 2, l, m, pos, val);
    } else {
        update(id * 2 + 1, m + 1, r, pos, val);
    }
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}
```

## Range Update Query :

### Range update query means updateing the values of array of a given range. We use the concept of **Lazy Propagation** to update the values of a given range.

In Lazy propagation we create onther tree intitialising its value to 0, called lazy tree. Which stores that the node of segement tree is need to be updated or not. So whenver we calculate the sum or udating the segment tree we check if lazy tree has some values or not, if lazy[idx] != 0 then we update the value of segement tree and check if the child of that segment tree exists or not by checking (l==h) or not. If it is not then we update the childs the lazy tree and return .

So, basically we dont update all value of segment tree at once, we update the value of segment tree when we need it.

[Segment Tree with Lazy Propagation](/Segment%20Tree/Range_Update_Query_Lazy_Propagation.cpp)

## 2D Prefix Sum :

### 2D Prefix sum pre[i][j] stores the sum of all elements in rectangle whose top left corner is (0,0) and bottom right corner is (i,j).

[2D Prefix Sum Question Forest Queries CSES](/Segment%20Tree/Forest_Queries.cpp)
