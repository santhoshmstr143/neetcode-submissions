class Solution {
public:
    vector<string> adj = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void solve(int i,string &temp,string &digits,vector<string> &ans)
    {
        if(i==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        int num = digits[i]-'0';
        for(auto it : adj[num])
        {
            temp += it;
            solve(i+1,temp,digits,ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> ans;
        string temp;
        solve(0,temp,digits,ans);
        return ans;
    }
};
