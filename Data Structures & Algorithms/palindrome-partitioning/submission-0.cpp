class Solution {
public:
    bool palin(int l, int r, string &s)
    {
        while(l < r)
        {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }

        return true;
    }
    void solve(int i,vector<string> &temp,string &s, vector<vector<string>> &ans)
    {
        if(i==s.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();j++)
        {
            if(!palin(i,j,s)) continue;

            temp.push_back(s.substr(i,j-i+1));
            solve(j+1,temp,s,ans);
            temp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        solve(0,temp,s,ans);
        return ans;
    }
};
