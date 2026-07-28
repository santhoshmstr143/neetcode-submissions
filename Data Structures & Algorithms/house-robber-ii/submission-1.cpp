class Solution {
public:
    int solve(int i,vector<int> &nums,vector<int>&dp)
    {
        if(i<0) return 0;
        if(dp[i]!= -1) return dp[i];

        int pick = nums[i] + solve(i-2,nums,dp);
        int notpick = solve(i-1,nums,dp);
        return dp[i] = max(pick,notpick);
    }
    int rob2(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(n-1,nums,dp);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> a1(nums.begin(),nums.end()-1);
        vector<int> a2(nums.begin()+1,nums.end());
        return max(rob2(a1),rob2(a2));
    }
};
