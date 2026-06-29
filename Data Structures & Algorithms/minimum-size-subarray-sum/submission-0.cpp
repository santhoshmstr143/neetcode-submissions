class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int len = 1e9;
        int l = 0;
        int sum = 0;
        for(int r =0;r<n;r++)
        {
            sum += nums[r];
            while(sum >= target)
            {
                len = min(len,r-l+1);
                sum -= nums[l];
                l++;
            }
        }
        return (len!=1e9)?len:0;
    }
};