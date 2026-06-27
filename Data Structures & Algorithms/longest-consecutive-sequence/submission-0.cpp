class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int c = nums[0],cnt = 1,ans = 1;
        for(int i =1;i<n;i++)
        {
            if(nums[i]==nums[i-1]) continue;
            if(nums[i]==c+1)
            {
                cnt++;
                c=nums[i];
                ans = max(cnt,ans);
            }
            else
            {
                c = nums[i];
                cnt = 1;
            }
        }
        return ans;
    }
};
