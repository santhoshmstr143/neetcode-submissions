class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &a)
    {
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 0;
        if(i>0 && a[i-1][j]!=1) ans += solve(i-1,j,dp,a);
        if(j>0 && a[i][j-1]!=1) ans += solve(i,j-1,dp,a);
        return dp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1) return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,dp,obstacleGrid);
    }
};