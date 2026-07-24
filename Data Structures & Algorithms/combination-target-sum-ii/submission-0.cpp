class Solution {
public:
    void solve(int i,int sum,vector<vector<int>> &ans,vector<int> &temp,vector<int> &nums)
    {
        if(sum==0) 
        {
            ans.push_back(temp);
            return;
        }
        if(i==nums.size() || nums[i]>sum) return;
        if(sum>=nums[i])
        {
            temp.push_back(nums[i]);
            solve(i+1,sum-nums[i],ans,temp,nums);
            temp.pop_back();
        }
        int j = i+1;
        while(j<nums.size() && nums[j]==nums[i])
        {
            j++;
        }
        solve(j,sum,ans,temp,nums);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,target,ans,temp,nums);
        return ans;
    }
};
