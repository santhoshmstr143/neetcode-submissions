class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i =0;i<n;i++)
        {
            int rem = k - nums[i];
            if(mp.find(rem)!=mp.end())
            {
                return {mp[rem]+1,i+1};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
