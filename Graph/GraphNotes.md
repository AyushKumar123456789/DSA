## Directed Graph Cycle Detection Code: (3 methods)

### 1. Using Color / DFS.

```
bool cycleCheck(vector<int>adj[],int node,vector<int>&color)
{
    bool check = 0;

    color[node]=1;
    for(auto ch:adj[node])
    {
        if(color[ch]==0)
        {
            check |= cycleCheck(adj,ch,color);
        }
        else if(color[ch]==1)
        {
            check = 1;
        }
    }

    color[node]=2;
    return check;
}

int main()
{
   vector<int>color(v,0);
    bool check = 0;
    for(int i=0;i<v;i++)
    {
        if(color[i]==0)
        {
            check |= cycleCheck(adj,i,color);
        }
    }
    //Check 1 then cycle.
    //check 0 then not cycle.

}
```

### 2. Using BFS or Kahn’s algorithm:

Uses the concept that if TOPOLIGICAL sort is possible then no cycle else cycle.

#### Logic : Try to find the topological sort of the graph if it is possible then no cycle else cycle. So, create a indegree array and push all the nodes with indegree 0 in the queue and then pop the node and reduce the indegree of the child nodes and push the child nodes with indegree 0 in the queue and repeat the process until the queue is empty.

```
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto ch:adj[i])
            {
                indegree[ch]++;
            }
        }
        queue<int>Q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0){
                Q.push(i);
            }
        }
        vector<int>topo;
        while(!Q.empty())
        {
            int node = Q.front();
            topo.push_back(node);
            Q.pop();
            for(auto ch:adj[node])
            {
                indegree[ch]--;
                if(indegree[ch]==0)
                {
                    Q.push(ch);
                }
            }
        }
        return topo.size()!=V;
    }

```

### 3. Using DFS/(visited & dfs_visited arrays ) :

Using similar concept as used in color .

```
    bool dfs(vector<int>adj[],int node,vector<int>&vis,vector<int>&dfs_vis)
    {
        vis[node] = 1;
        dfs_vis[node] = 1;
        bool check = 0;
        for(auto ch:adj[node])
        {
            if(!vis[ch])
            {
                check |= dfs(adj,ch,vis,dfs_vis);
            }
            if(dfs_vis[ch]==1)
            {
                check = 1;
            }
        }
        dfs_vis[node] = 0;
        return check;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        vector<int>dfs_vis(V,0);
        bool check = 0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                check |= dfs(adj,i,vis,dfs_vis);
            }
        }
        return check;

    }

```

## UNDIRECTED Graph Cycle Detection Code: (2 Method)

### 1. Using DFS & parent array.

1. First create a parent array.

2. Then for every child of a node, make parent of child = node and when you encounter the visited node check if parent[node]! =child, then it is a cycle.

```

    bool cycleCheck(vector<int>adj[],vector<int>&vis,vector<int>&parent,int node)
        {
            vis[node]=1;
            bool check  = 0;
            for(auto ch:adj[node])
            {
                if(!vis[ch])
                {
                    parent[ch]=node;
                    check |= cycleCheck(adj,vis,parent,ch);
                }
                else if(parent[node]!=ch)
                {
                    check = 1;
                }
            }
            return check;
        }
    int main()
    {
        vector<int>vis(V,0);
        vector<int>parent(V,-1);
        bool check = 0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                check |= cycleCheck(adj,vis,parent,i);
            }
        }
        return check;
    }

```

### 2. Using BFS.

Uses same concept as dfs but traverse through bfs and queue is made of pair, <node,parent>

```

bool bfs(vector<int>edges[], vector<int> &vis, int idx) {
queue<pair<int, int>> Q;
Q.push({idx,-1});
while(!Q.empty())
{
pair<int,int> x = Q.front();
Q.pop();
vis[x.first]=1;
for(auto ch:edges[x.first])
{
if(vis[ch]==0)
{
vis[ch]=1;
Q.push({ch,x.first});
}
else if(x.second!=ch){

                    return 1;

            }
        }
    }
    return 0;

}

```

- ### OR you can use different parent array like DFS.

```
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        vector<int>parent(V,-1);
        queue<int>Q;
        bool check = 0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                Q.push(i);
                vis[i]=1;
                while(!Q.empty())
                {
                    int node = Q.front();
                    Q.pop();
                    for(auto ch:adj[node])
                    {
                        if(!vis[ch])
                        {
                            vis[ch] = 1;
                            parent[ch] = node;
                            Q.push(ch);
                        }
                        else
                        {
                            if(parent[node]!=ch)
                            {
                                check = 1;
                            }
                        }
                    }
                }
            }
        }
        return check;
    }
```

## Seive of Eratosthenes :

It is used to find that given number is prime or not , (and number in range of 0 to 1e6) it is one time computation method so it is helpful for multiple query :

```

Vector<int>prime(1e6,1);
prime[0]=prime[1]=0;
for(int i=2;i*i<=1e6;i++){
if(prime[i]==1)
{
for (int multiple = i * i; multiple <= 1e6; multiple += i) {
prime[multiple] = 0;
}
}
}

Time Complexity=> O(xlog(log(sqrt(x)))) = xlog(½\*log(x)) = O(xlog(log(x)))

```

## Dijkstra Algorithm :

Used to find minimum distance of every node from source and can’t handle negative edges as well as negative cycle.

```

//Here adjacent list in the form of vector<vector<int>>adj[]
int MAX_INT = 1000000;
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
vector<int>dist(V,INT_MAX);
pq.push({0,S});
dist[S]=0;
while(!pq.empty())
{
auto temp = pq.top();
pq.pop();
auto node = temp.second;
auto cur_node_dist = temp.first;
if(dist[node]<cur_node_dist)continue;
for(auto ch:adj[node])
{
int child_dist = cur_node_dist + ch[1];
if(child_dist<dist[ch[0]])
{
dist[ch[0]] = child_dist;
pq.push({child_dist,ch[0]});
}
}

     }
     return dist;

}
O(V^2\*logV) -> time complexity in worst case of dense graph.

```

## TOPOSORT CODE :

### 1. Using simple DFS and Reversing andy of its DFS vectors , But you need to be sure that Cycle is not present in the graph.

```

    void dfs(vector<int>adj[],vector<int>&vis,vector<int>&topo_sort,int node)
    {
        vis[node]=1;
        for(auto ch:adj[node])
        {
            if(!vis[ch])
            {
                dfs(adj,vis,topo_sort,ch);
            }
        }
        topo_sort.push_back(node);
    }
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int>topo_sort;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(adj,vis,topo_sort,0);
            }
        }
        reverse(topo_sort.begin(),topo_sort.end());
        return topo_sort;
    }

```

### 2. BFS TOPOSORT : (Using Indegree)

```

    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto ch:adj[i])
            {
                indegree[ch]++;
            }
        }
        queue<int>Q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                Q.push(i);
            }
        }
        vector<int>topo;
        while(!Q.empty())
        {
            int node = Q.front();
            topo.push_back(node);
            Q.pop();
            for(auto ch:adj[node])
            {
                indegree[ch]--;
                if(indegree[ch]==0)
                {
                    Q.push(ch);
                }
            }
        }
        return topo;
    }

```

## DSU (Disjoint set union) :

### What is a Disjoint set data structure?

- ### Two sets are called disjoint sets if they don’t have any element in common, the intersection of sets is a null set.

### What it is used for ?

- ### Consider a scenario where you have to find that two nodes belong to same components or not , DSU does it in O(1)

### DSU functoin provide :

### 1. Union : It is used to merge two sets.

### 2. Find : It is used to find the parent/Representative of the set.

### 3. MakeSet : It is used to create a set of a single element.

### DSU : Partitioning the individuals into different sets according to the groups in which they fall. This method is known as a Disjoint set Union which maintains a collection of Disjoint sets and each set is represented by one of its members call ultimate parent.

### Data Structure used for DSU :

1. ### Array : Parent[] : It is used to store the parent of the node.
2. ### Array : Rank[] : It is used to store the height of the tree.
   ### OR
3. ### Array : Size[] : It is used to store the size of the tree.
4. ### For DSU implementation, we need to create Three functions : Find and Union(Rank/size) and One for initialization of the parent of every node to itself and Size of Rank/Size vector

### Find opeartion :

```
        int findUpar(int node){
        if(node == parent[node])
        {
            return node;
        }
        return parent[node] = findUpar(parent[node]);//path compression

    }
        Time Complexity: O(log n) on average per call because of path compression without it O(n).
```

### Union operation (Two Ways) :

It is used to merge two sets which is nothind but two trees and make them one tree we have to just make the parent of every node of one tree to the parent of the other tree , So there are two ways to decide which tree come under other or which tree become parent of other tree.

- ### Union by Rank :

  Here rank[i] is the height of the tree representing the set containing i.
  If the rank of left is less than the rank of right, then it’s best to move left under right, because that won’t change the rank of right (while moving right under left would increase the height). In the same way, if the rank of right is less than the rank of left, then we should move right under left.
  If the ranks are equal, it doesn’t matter which tree goes under the other, but the rank of the result will always be one greater than the rank of the trees.

  ```
   void unionByRank(int u,int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v)return;
        if(Rank[ulp_u]<Rank[ulp_v]){
           parent[ulp_u] = ulp_v;
        }
        else if(Rank[ulp_v]<Rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            Rank[ulp_u]++;
        }
    }
    Time Complexity: O(alpha(n)) on average per call because of path compression without it O(n).
  ```

- ### Union by Size :

  If i is a representative of a set, size[i] is the number of the elements in the tree representing the set.
  If the size of left is less than the size of right, then it’s best to move left under right and increase size of right by size of left. In the same way, if the size of right is less than the size of left, then we should move right under left. and increase size of left by size of right.
  If the sizes are equal, it doesn’t matter which tree goes under the other.

  ```
  void unionBySize(int u,int v){
  int ulp_u = findUpar(u);
  int ulp_v = findUpar(v);
  if(ulp_u == ulp_v)return;
  if(Size[ulp_u]<Size[ulp_v]){
  parent[ulp_u] = ulp_v;
  Size[ulp_v] += Size[ulp_u];
  }
  else {
  parent[ulp_v] = ulp_u;
  Size[ulp_u] += Size[ulp_v];
  }

      }
      Time complexity: O(log n) without Path Compression.
      Time complexity: O(alpha(n)) with Path Compression.
  ```

### Complete CODE :

```
    vector<int>Rank,parent;

    vector<int>Size;
    class DisjointSet{
    public:
    void print_rank(){
    for(int i=1;i<Size.size();i++)
    {
    cout<<Size[i]<<" ";
    }
    cout<<endl;
    }
    DisjointSet(int n){
    Rank.resize(n+1,0);
    Size.resize(n+1,1);
    parent.resize(n+1,0);
    for(int i=0;i<=n;i++){
    parent[i] = i;
    }
    }


    int findUpar(int node){
    if(node == parent[node])
    {
    return node;
    }
    return parent[node] = findUpar(parent[node]);//path compression

    }

        void unionByRank(int u,int v){
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            if(ulp_u == ulp_v)return;
            if(Rank[ulp_u]<Rank[ulp_v]){
               parent[ulp_u] = ulp_v;
            }
            else if(Rank[ulp_v]<Rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                Rank[ulp_u]++;
            }
        }

    void unionBySize(int u,int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v)return;
        if(Size[ulp_u]<Size[ulp_v]){
           parent[ulp_u] = ulp_v;
           Size[ulp_v] += Size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            Size[ulp_u] += Size[ulp_v];
        }

    }

};
```

# MST (Minimum Spanning Tree) , Two Algorithms :

- ## Kruskal Algorithm : (Uses DSU CONCEPT)

### Steps :

- ### Create a vector pair<int,pair<int,int>> = {weight,{node1,node2}}
- ### Then sort it according to the weight in ascending order.
- ### Then iterate through the sorted vector and Do union of the nodes if they are not in the same set and not if they are not in same set (i.e if(parent[node1]!=parent[node2]) then do union of the nodes and add the weight to the answer.

```
// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// DSU data structure
// path compression + rank by union
class DSU {
	int* parent;
	int* rank;

public:
	DSU(int n)
	{
		parent = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	// Find function
	int find(int i)
	{
		if (parent[i] == -1)
			return i;

		return parent[i] = find(parent[i]);
	}

	// Union function
	void unite(int x, int y)
	{
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
			}
			else if (rank[s1] > rank[s2]) {
				parent[s2] = s1;
			}
			else {
				parent[s2] = s1;
				rank[s1] += 1;
			}
		}
	}
};

class Graph {
	vector<vector<int> > edgelist;
	int V;

public:
	Graph(int V) { this->V = V; }

	// Function to add edge in a graph
	void addEdge(int x, int y, int w)
	{
		edgelist.push_back({ w, x, y });
	}

	void kruskals_mst()
	{
		// Sort all edges
		sort(edgelist.begin(), edgelist.end());

		// Initialize the DSU
		DSU s(V);
		int ans = 0;
		cout << "Following are the edges in the "
				"constructed MST"
			<< endl;
		for (auto edge : edgelist) {
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			// Take this edge in MST if it does
			// not forms a cycle
			if (s.find(x) != s.find(y)) {
				s.unite(x, y);
				ans += w;
				cout << x << " -- " << y << " == " << w
					<< endl;
			}
		}
		cout << "Minimum Cost Spanning Tree: " << ans;
	}
};

// Driver code
int main()
{
	Graph g(4);
	g.addEdge(0, 1, 10);
	g.addEdge(1, 3, 15);
	g.addEdge(2, 3, 4);
	g.addEdge(2, 0, 6);
	g.addEdge(0, 3, 5);

	// Function call
	g.kruskals_mst();

	return 0;
}

```

### Complexity Analysis :

- Time Complexity: O(E _ logE) or O(E _ logV)

  1. Sorting of edges takes O(E \* logE) time.
  2. After sorting, we iterate through all edges and apply the find-union algorithm. The find and union operations can take at most O(logV) time.
  3. So overall complexity is O(E _ logE + E _ logV) time.
     The value of E can be at most O(V2), so O(logV) and O(logE) are the same. Therefore, the overall time complexity is O(E * logE) or O(E*logV)

- Auxiliary Space: O(V + E), where V is the number of vertices and E is the number of edges in the graph.

- ## Prim Algorithm :

## Bellman Ford Algorithm : (LEFT)

## Floyd Warshall Algorithm : (LEFT)

## Tarjan Algorithm : (LEFT)

## Articulation Point : (LEFT)

## Bridge : (LEFT)

## Strongly Connected Component : (LEFT)

## Eulerian Path : (LEFT)

## Hamiltonian Path : (LEFT)

## Travelling Salesman Problem : (LEFT)

## Bipartite Graph : (LEFT)

## Maximum Bipartite Matching : (LEFT)

## Maximum Flow : (LEFT)

## Minimum Cut : (LEFT)

## KMP Algorithm : (LEFT)

## Rabin Karp Algorithm : (LEFT)

## Z Algorithm : (LEFT)

## Manacher Algorithm : (LEFT)

## Aho Corasick Algorithm : (LEFT)

## Suffix Array : (LEFT)

## Heap Code :

### Heapify

```

void heapify(vector<int>&nums,int n,int i)
{
int left = 2*i+1;
int right = 2*i+2;
int largest = i;
if(left<n && nums[largest]<nums[left])
{
largest = left;
}
if(right<n && nums[largest]<nums[right])
{
largest = right;
}
if(largest!=i)
{
swap(nums[largest],nums[i]);
heapify(nums,n,largest); }}

void buildHeap(int arr[],int n){
for(int i=n/2;i>0;i--)
{
Heapify(arr,n,i);
}
}
O(n) -> time complexity

```

## TRIE : (Dictonary Code)

```

#include<bits/stdc++.h>
using namespace std;

struct Node{
Node\* links[26];
bool flag = false;

    bool containKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }

    void put(char ch,Node* node)
    {
        links[ch-'a'] = node;
    }

    Node* get(char ch)
    {
        return links[ch-'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }

};

class Trie{
private:
Node _root;
public:
Trie(){
root = new Node();
}
void insert(string word){
Node_ node = root;
for(int i=0;i<word.size();i++)
{
if(!node->containKey(word[i]))
{
node->put(word[i],new Node());
}
node = node->get(word[i]);
}
node->setEnd();
}
bool search(string word){
Node*node = root;
for(int i=0;i<word.size();i++)
{
if(!node->containKey(word[i]))
{
return 0;
}
else{
node = node->get(word[i]);
}
}
return node->flag;
}
bool startsWith(string prefix){
Node *node = root;
for(int i=0;i<prefix.size();i++)
{
if(!node->containKey(prefix[i]))
{
return 0;
}
else{
node = node->get(prefix[i]);
}
}
return 1;
}
};
Trie(Max Xor Code) :
class Node{
public:
Node* links[2];
void put(int i,Node* node)
{
links[i] = node;
}
Node\* get(int i)
{
return links[i];
}
bool containKey(int i)
{
return links[i]!=NULL;
}
};

class Trie{
private:
Node* root = new Node();
public:
void insert(int num)
{
Node* node = root;
int temp = num;
for(int i=31;i>=0;i--)
{
int bit = (temp & (1<<i))?(1):0;
if(!node->containKey(bit))
{
node->put(bit,new Node());
}
node = node->get(bit);
}
}
int Xor(int num)
{
int ans = 0;
Node\* node = root;
int temp = num;
for(int i=31;i>=0;i--)
{
int bit = (temp & (1<<i))?(1):0;
int rev_bit = !bit;

            if(node->containKey(rev_bit))
            {
                node = node->get(rev_bit);
                ans += pow(2,i);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return ans;
    }
     int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            trie.insert(nums[i]);
        }
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,trie.Xor(nums[i]));
        }
        return maxi;

    }

};

```

## MergeSort : (O(logn)(n))

```

void merge(vector<int>&arr,int l1,int r1,int l2,int r2)
{
int n = r1-l1+1;
int m = r2-l2+1;
int a1[n],a2[m];
int j = 0;
for(int i=l1;i<=r1;i++)
{
a1[j] = arr[i];
j++;
}
j=0;
for(int i=l2;i<=r2;i++)
{
a2[j] = arr[i];
j++;
}
int k = l1;
int i=0;
j=0;
while(i<n && j<m)
{
if(a1[i]<=a2[j])
{
arr[k] = a1[i];
i++; k++;
}
else if(a1[i]>a2[j])
{
arr[k] = a2[j];
j++;
k++;
}
}
while(i<n){
arr[k] = a1[i];
k++;i++;
}
while(j<m){
arr[k] = a2[j];
k++; j++;
}
}

void mergeSort(vector<int>&arr,int left,int right)//arr,0,arr.size()
{
if(left<right)
{
int mid = (left + right)/2;
mergeSort(arr,left,mid);
mergeSort(arr,mid+1,right);
merge(arr,left,mid,mid+1,right);
}
}

```

```

```

```

```
