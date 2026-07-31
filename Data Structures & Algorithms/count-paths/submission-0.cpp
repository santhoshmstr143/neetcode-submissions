class Solution {
public:
    int dx[4] = {0,-1};
    int dy[4] = {-1,0};
    int solve(int i,int j,vector<vector<int>> &dp)
    {
        int n = dp.size();
        int m = dp[0].size();
        if(i==0 && j==0)
        {
            return 1;
        }
        if(dp[i][j]!= -1) return dp[i][j];

        int ans = 0;
        for(int k = 0;k<2;k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if(x<0 || y <0) continue;
            ans += solve(x,y,dp);
        }
        return dp[i][j] = ans;
    }
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,dp);
    }
};
