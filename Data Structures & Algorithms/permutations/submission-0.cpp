class Solution {
public:
    void solve(vector<int> &nums, vector<int> &temp,vector<vector<int>> &ans, vector<int> &vis)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(vis[i]) continue;
            vis[i]=1;
            temp.push_back(nums[i]);
            solve(nums,temp,ans,vis);
            temp.pop_back();
            vis[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<int> vis(nums.size(),0);
        vector<vector<int>> ans;
        solve(nums,temp,ans,vis);
        return ans;
    }
};
