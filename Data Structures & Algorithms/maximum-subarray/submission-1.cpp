class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        vector<int> pre(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            pre[i] = sum;
        }
        int mn = 0;
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            ans = max(ans,pre[i]-mn);
            mn = min(mn,pre[i]);
        }
        return ans;
    }
};
