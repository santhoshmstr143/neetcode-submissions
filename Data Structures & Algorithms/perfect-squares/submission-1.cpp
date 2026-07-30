class Solution {
public:
    int solve(int idx,vector<int> &sq, vector<vector<int>>&dp,int n)
    {
        if(n==0) return 0;
        if(idx==sq.size()) return 1e9;
        if(dp[idx][n]!=-1) return dp[idx][n];

        int notpick = solve(idx+1,sq,dp,n);
        int pick = 1e9;
        if(sq[idx]<=n)
        {
            pick = 1 + solve(idx,sq,dp,n-sq[idx]);
        }
        return dp[idx][n] = min(pick,notpick);        
    }
    int numSquares(int n) {
        vector<int> sq;
        for(int i=1;i*i<=n;i++)
        {
            sq.push_back(i*i);
        }
        int len = sq.size();
        vector<vector<int>> dp(len,vector<int>(n+1,-1));
        return solve(0,sq,dp,n);
    }
};