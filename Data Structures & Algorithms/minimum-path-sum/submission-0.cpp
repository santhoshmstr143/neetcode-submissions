class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &a)
    {
        if(i==0 && j==0) return a[i][j];
        if(dp[i][j]!=-1) return dp[i][j];

        int l = 1e9;
        if(i>0) l = solve(i-1,j,dp,a);
        int r = 1e9;
        if(j>0) r = solve(i,j-1,dp,a);
        
        return dp[i][j] = a[i][j] + min(l,r);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,dp,grid);
    }
};