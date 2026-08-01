class Solution {
public:
    int solve(int idx,int k,vector<int> &coins,vector<vector<int>> &dp)
    {
        if(k==0) return 1;
        if(idx==coins.size()) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];

        int notpick = solve(idx+1,k,coins,dp);
        int pick = 0;
        if(coins[idx]<=k)
        {
            pick = solve(idx,k-coins[idx],coins,dp);
        }
        return dp[idx][k] = pick + notpick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(0,amount,coins,dp);
    }
};