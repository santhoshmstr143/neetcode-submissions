class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> mx(n);
        vector<int> mn(n);
        mx[0] = nums[0];
        mn[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            mx[i] = max(nums[i], max(nums[i]*mx[i-1],nums[i]*mn[i-1]));
            mn[i] = min(nums[i], min(nums[i]*mn[i-1],nums[i]*mx[i-1]));
        }
        return *max_element(mx.begin(),mx.end());
    }
};
