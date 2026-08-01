class Solution {
public:
    int solve(int i,int k,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i==nums.size()) return k==0;
        if(dp[i][k]!= -1) return dp[i][k];

        int np = solve(i+1,k,nums,dp);
        int p = 0;
        if(nums[i]<=k)
            p = solve(i+1,k-nums[i],nums,dp);
        return dp[i][k] = p + np;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for(auto it : nums) total += it;
        if(abs(target) > total)
            return 0;

        if((total + target) % 2)
            return 0;
        target = (target+total)/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(0,target,nums,dp);
    }
};
