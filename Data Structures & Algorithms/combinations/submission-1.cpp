class Solution {
public:
    void solve(int i,int n,int k,vector<vector<int>> &ans,vector<int> &temp)
    {
        if(temp.size()==k) 
        {
            ans.push_back(temp);
            return;
        }
        if(i>n) return;
        
        if(n-i+1 < k - temp.size()) return;
        temp.push_back(i);
        solve(i+1,n,k,ans,temp);
        temp.pop_back();
        
        solve(i+1,n,k,ans,temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,n,k,ans,temp);
        return ans;
    }
};
