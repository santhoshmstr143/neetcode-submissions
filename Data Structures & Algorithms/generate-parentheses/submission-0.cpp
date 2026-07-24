class Solution {
public:
    void solve(int i,int n,string temp,vector<string> &ans)
    {
        if(n==0 && i==0)
        {
            ans.push_back(temp);
            return;
        }
        if(i>0)
        {
            temp += ')';
            solve(i-1,n,temp,ans);
            temp.pop_back();
        }
        if(n>0)
        {
            temp+= '(';
            solve(i+1,n-1,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> ans;
        solve(0,n,temp,ans);
        return ans;
    }
};
