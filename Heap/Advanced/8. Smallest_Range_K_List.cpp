// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Using K pointers stored in a vector

Algorithm:
The idea is to keep k pointers which will constitute the elements in the range, by taking the min and max of the K elements the range can be formed.
 Initially, all the pointers will point to the start of all the K arrays.
  Store the range max to min. If the range has to be minimized then either the minimum value has to be increased or the maximum value has to be decreased.
  To decrease the maximum value we have to move our pointer of current maximum to the left and since we are currently at 0 the index of every list so we can’t move our pointer to left, hence we can’t decrease the current max.
   So, the only possible option to get a better range is to increase the current minimum. To continue increasing the minimum value,
increase the pointer of the list containing the minimum value and update the range until one of the lists exhausts.

Time Complexity: O(N * K * k) where N is the number of elements in any list and K is the number of lists .
Space Complexity: O(N * K) + O(K) = O(N * K)

*/

/*
Approach 2: Using priority queue

Algorithm:
1. We declare a Priority Queue<Node> ,Node class consists of current row,current column and current data.
2. We first push every details of first column in the queue.
3. while pushing elements in the queue , we always keep a track of the maximum element achieved so far.
4. While poping the smallest element , we update the min value and compare with range ,ie max-min and if the smaller than previous then we update start to min and end to max.
Atlast we print start and end.
*/