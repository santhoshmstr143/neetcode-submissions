class Solution {
public:
    int solve(int i,int buy,vector<int>&a,vector<vector<int>> &dp)
    {
        if(i>=a.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==0)
        {
            return dp[i][buy] = max(-a[i]+solve(i+1,1-buy,a,dp),
                                    solve(i+1,buy,a,dp));
        }
        else
        {
            return dp[i][buy] = max(a[i]+solve(i+2,1-buy,a,dp),
                                    solve(i+1,buy,a,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,0,prices,dp);
    }
};
