class Solution {
public:
    bool solve(int i,vector<int> &nums,vector<int> &subset,int target)
    {
        if(i==nums.size())
        {
            for(auto it : subset)
            {
                if(it!=target) return false;
            }
            return true;
        }
        for(int j=0;j<subset.size();j++)
        {
            if(subset[j]+nums[i]>target) continue;

            subset[j] += nums[i];

            if(solve(i+1,nums,subset,target)) return true;

            subset[j] -= nums[i];
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto it : nums)
        {
            sum += it;
        }
        if(sum%k) return false;
        int target = sum/k;
        sort(nums.rbegin(),nums.rend());
        if(nums[0]>sum) return false;
        vector<int> subset(k,0);
        return solve(0,nums,subset,target);
    }
};