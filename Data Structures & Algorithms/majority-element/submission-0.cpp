class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int e = nums[0];
        int cnt = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(cnt==0) e = nums[i];
            else if(nums[i]==e)
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