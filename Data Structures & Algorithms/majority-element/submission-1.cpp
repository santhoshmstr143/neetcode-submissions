class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int e = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt==0) e = nums[i];
            if(nums[i]==e)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        return e;
    }
};