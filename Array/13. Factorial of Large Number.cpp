// https://www.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

/*
1000! has about 2000 digits,

Thing to remember : carry should be taken care with while Loop since array element contain only one digit

*/

vector<int> factorial(int N)
{
    vector<int> ans(1, 1);
    for (int i = 2; i <= N; i++)
    {
        int carry = 0;
        for (int j = 0; j < ans.size(); j++)
        {
            long long mul = ans[j] * i + carry;
            ans[j] = mul % 10;
            carry = mul / 10;
        }
        while (carry)
        {
            ans.push_back(carry % 10);
            carry /= 10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}