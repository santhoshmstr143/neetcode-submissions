class Solution {
public:

    bool solve(int idx,int k,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(k==0) return true;
        if(idx==nums.size())
        {
            return false;
        }
        if(dp[idx][k]!= -1) return dp[idx][k];

        int notpick = solve(idx+1,k,nums,dp);
        int pick = false;
        if(nums[idx]<=k)
        {
            pick = solve(idx+1,k-nums[idx],nums,dp);
        }
        return dp[idx][k] = pick || notpick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums) sum += it;
        if(sum%2) return false;
        sum /= 2;

        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(0,sum,nums,dp);
    }
};
