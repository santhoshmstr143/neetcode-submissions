class Solution {
public:
    bool solve(int i,vector<int> &dp,string &s,unordered_set<string>& st)
    {
        if(i==s.size()) return true;
        if(dp[i]!= -1) return dp[i];

        string c = "";
        for(int j = i;j<s.size();j++)
        {
            c += s[j];
            if(st.find(c)!=st.end())
            {
                if(solve(j+1,dp,s,st))
                {
                    return dp[i]=true;
                }
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<int> dp(n,-1);
        return solve(0,dp,s,st);
    }
};
