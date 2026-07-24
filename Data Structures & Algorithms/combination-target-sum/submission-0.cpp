class Solution {
public:
    void solve(int i,int sum,vector<vector<int>> &ans,vector<int> &temp,vector<int> &nums)
    {
        if(sum==0) 
        {
            ans.push_back(temp);
            return;
        }
        if(i==nums.size()) return;
        if(sum>=nums[i])
        {
            temp.push_back(nums[i]);
            solve(i,sum-nums[i],ans,temp,nums);
            temp.pop_back();
        }
        solve(i+1,sum,ans,temp,nums);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,target,ans,temp,nums);
        return ans;
    }
};
