class Solution {
public:
    bool solve(int i,int j,string t1,string t2,string s,vector<vector<int>> &dp)
    {
        if(i==t1.size() && j==t2.size()) return true; 

        int k = i+j;
        if(dp[i][j]!= -1) return dp[i][j];

        int res = false;
        if(i<t1.size() && t1[i]==s[k])
        {
            res |= solve(i+1,j,t1,t2,s,dp);
        }
        if(j<t2.size() && t2[j]== s[k])
        {
            res |= solve(i,j+1,t1,t2,s,dp);
        }
        return dp[i][j] = res;

    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,s1,s2,s3,dp);
    }
};
