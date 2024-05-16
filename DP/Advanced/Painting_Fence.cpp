//https://www.geeksforgeeks.org/problems/painting-the-fence3727/1

/*
Approach , two conditions 
1. If current and previous fence should be of same color
2. If current and previous fence should be of different color

IF there are k colors and n fences
n=1 -> same = 0 and different  = k
n=2 -> same = k and different = k*(k-1)
n=3 -> same = k*(k-1) and different = k*(k-1)*(k-1) // Here you see different = (precious total)*(k-1) and same = previous different

In general : 
total[i] = same[i] + diff[i]
same[i]  = diff[i-1]
diff[i]  = total[i-1] * (k-1)
*/

//Direct GO to iterative approach
     #include <bits/stdc++.h>
     using namespace std;
    
    long long countWays(int n, int k) {
        vector<long long> diff(n + 1, 0);
        vector<long long> same(n + 1, 0);
        diff[0] = k;
        same[0] = 0ll;
        
        for (int i = 1; i <= n; i++) {
            same[i] = diff[i - 1];
            diff[i] = (((same[i - 1] % 1000000007ll) + (diff[i - 1] % 1000000007ll)) % 1000000007ll) * ((k - 1) ) % 1000000007ll;
        }
        return (diff[n-1] % 1000000007ll + same[n-1] % 1000000007ll) % 1000000007ll;
    }

//Time Complexity: O(n)
//Space Complexity: O(n)

//Space optimization

    long long countWays(int n, int k) {
        long long diff = k;
        long long same = 0ll;
        
        for (int i = 1; i < n; i++) {
            long long temp = diff;
            diff = (((same % 1000000007ll) + (diff % 1000000007ll)) % 1000000007ll) * ((k - 1) ) % 1000000007ll;
            same = temp;
        }
        return (diff % 1000000007ll + same % 1000000007ll) % 1000000007ll;
    }

//Time Complexity: O(n)
//Space Complexity: O(1)