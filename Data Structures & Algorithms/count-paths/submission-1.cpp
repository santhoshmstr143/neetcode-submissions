class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &dp)
    {
        if(i==0 && j==0)
        {
            return 1;
        }
        if(dp[i][j]!= -1) return dp[i][j];

        int ans = 0;
        if(i>0) ans += solve(i-1,j,dp);
        if(j>0) ans += solve(i,j-1,dp);
        return dp[i][j] = ans;
    }
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,dp);
    }
};
