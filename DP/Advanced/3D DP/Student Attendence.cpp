// https://leetcode.com/problems/student-attendance-record-ii/

/*
Recursion Easy Solution
*/

#define ll long long
#define MOD 1000000007ll

class Solution
{
public:
    ll f(ll day, ll cont_late, ll absent, vector<vector<vector<ll>>> &dp)
    {
        if (day == 0)
        {
            return 1;
        }
        if (dp[day][cont_late][absent] != -1)
        {
            return dp[day][cont_late][absent];
        }
        ll ans = 0;
        if (cont_late < 2)
        {
            ans += f(day - 1, cont_late + 1, absent, dp) % MOD;
        }
        if (absent == 0)
        {
            ans += f(day - 1, 0, absent + 1, dp) % MOD;
        }
        ans += f(day - 1, 0, absent, dp) % MOD;
        return dp[day][cont_late][absent] = ans % MOD;
    }

    ll checkRecord(ll n)
    {
        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(3, vector<ll>(2, -1)));
        ll ans = f(n, 0, 0, dp) % MOD;
        return ans;
    }
};

/*
Tabulation Solution
*/

#define ll long long
#define MOD 1000000007ll

class Solution
{
public:
    // ll f(ll day,ll cont_late,ll absent,vector<vector<vector<ll>>>&dp)
    // {
    //     if(day==0){
    //         return 1;
    //     }
    //     if(dp[day][cont_late][absent]!=-1){
    //         return dp[day][cont_late][absent];
    //     }
    //     ll ans = 0;
    //     if(cont_late < 2){
    //         ans+=f(day-1,cont_late+1,absent,dp)%MOD;
    //     }
    //     if(absent==0)
    //     {
    //         ans+=f(day-1,0,absent+1,dp)%MOD;
    //     }
    //         ans+=f(day-1,0,absent,dp)%MOD;
    //     return dp[day][cont_late][absent] = ans%MOD;
    // }

    ll checkRecord(ll n)
    {
        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(2 + 1, vector<ll>(3 + 1, 0)));
        // ll ans = f(n,0,0,dp)%MOD;
        // return ans;
        // dp[i][j][k] represent for i days , with k basent with j late total possible way

        dp[0][0][0] = 1;

        for (int i = 1; i <= n; ++i)
        {
            for (int a = 0; a <= 1; ++a)
            {
                for (int l = 0; l <= 2; ++l)
                {
                    // Add 'P' (present)
                    dp[i][a][0] = (dp[i][a][0] + dp[i - 1][a][l]) % MOD;

                    // Add 'A' (absent)
                    if (a > 0)
                    {
                        dp[i][a][0] = (dp[i][a][0] + dp[i - 1][a - 1][l]) % MOD;
                    }

                    // Add 'L' (late)
                    if (l < 2)
                    {
                        dp[i][a][l + 1] = (dp[i][a][l + 1] + dp[i - 1][a][l]) % MOD;
                    }
                }
            }
        }
        return (dp[n][0][0] + dp[n][0][1] + dp[n][0][2] + dp[n][1][0] + dp[n][1][1] + dp[n][1][2]) % MOD;
    }
};