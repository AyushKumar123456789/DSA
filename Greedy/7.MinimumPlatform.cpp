/*
Good Question Remmber it
*/
/*
Question:-
Given arrival and departure times of all trains that reach a railway station.
Your task is to find the minimum number of platforms required for the railway station so that no train waits.

Approach:-
1. Sort the arrival and departure time of trains.
2. Create two pointers i=1, and j=0 and a variable count=1 to store the minimum number of platforms needed.
3. If the arrival time of the current train is less than or equal to the departure time of the train at pointer j,
 then one more platform is needed, so increase the count, and increment i.
4. If the arrival time of the current train is more than the departure time of the train at pointer j,
 then one platform can be removed, so decrease the count, and increment j.
5. Update the result with the maximum value of count.
6. Return the result.


*/

class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {

        sort(arr, arr + n);
        sort(dep, dep + n);

        int ans = 1;
        int count = 1;
        int i = 1, j = 0;
        while (i < n && j < n)
        {
            if (arr[i] <= dep[j]) // one more platform needed
            {
                count++;
                i++;
            }
            else // one platform can be reduced
            {
                count--;
                j++;
            }
            ans = max(ans, count); // updating the value with the current maximum
        }
        return ans;
    }
};