### The layman's way of analyzing the runtime of a memoized recursive function is :

Work per subproblem \* Number of subproblems

Recursive -> This approach is called **top-down**, as we can call the function with a query value and the calculation starts going from the top (queried value) down to the bottom (base cases of the recursion), and makes shortcuts via memorization on the way.

Iterative -> This approach is called **bottom-up**, Bottom up is exactly the opposite of top-down, you start at the bottom (base cases of the recursion), and extend it to more and more values.

## How to think in iterative DP?

### 1. Define what dp[i][j] or dp[i] will represent in your problem.

### 2. Initialize the base cases of the dp array.

#### KnapSack Problem:

    dp[i][j] = maximum value that can be obtained with a weight limit of j and first i items.

    Base Cases: dp[0][j] where 0<=j<=MaxWeight
    So, Maximum value that can be obtained by choosing the item at index 0 and weight can be 0 to maxWeight.

#### Coin Change Problem:

    dp[i][j] = Number of ways to make a sum of j using first i coins.

    Base Cases: dp[0][j] where 0<=j<=sum
    So, Number of ways to make a sum of j using only index 0 coins.
### Steps to write DP solution in interview
1. Explain what DP represent
2. write how DP is releated to previous DP and write it in comment
3. Think of base case and when it is needed and write it before iteration
