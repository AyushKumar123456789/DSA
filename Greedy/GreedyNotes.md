## [Activity Selection Problem](/Greedy/1.Activity_Selection.cpp)

- **Problem**: Given a set of activities, each with a start and finish time, select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
- **Approach**: Greedy
- **Algorithm**:
  1. Sort the activities based on their finish time.
  2. Select the first activity.
  3. For each remaining activity, if the start time of the activity is greater than or equal to the finish time of the last selected activity, select the activity.

## [Job Sequencing Problem](/Greedy/2.JobSequencing.cpp)

- **Problem**: Given a set of jobs, each with a deadline and profit, select the maximum profit subset of jobs that can be completed within their deadlines.
- **Approach**: Greedy
- **Algorithm**:
  1. Sort the jobs based on their profit in descending order.
  2. For each job, starting from the job with the highest profit, assign the job to the latest possible slot before its deadline.

## [Huffman Coding](/Greedy/3.HuffmanCoding.cpp)

- **Problem**: Given a set of characters and their frequencies, construct a binary tree such that the sum of the depths of all the characters is minimized.
- **Approach**: Greedy
- **Algorithm**:
  1. Create a min-heap of characters based on their frequencies.
  2. Extract the two characters with the lowest frequencies from the heap.
  3. Create a new internal node with the two characters as children and the sum of their frequencies as the frequency.
  4. Insert the new node back into the heap.
  5. Repeat steps 2-4 until only one node remains in the heap.

## [Fractional Knapsack Problem]
