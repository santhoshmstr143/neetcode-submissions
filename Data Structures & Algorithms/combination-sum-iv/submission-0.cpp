class Solution {
public:
    int solve(int k,vector<int>&nums,vector<int> &dp)
    {
        if(k==0) return 1;
        if(dp[k]!=-1) return dp[k];
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=k)
            {
                ans += solve(k-nums[i],nums,dp);
            }
        }
        return dp[k] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return solve(target,nums,dp);
    }
};