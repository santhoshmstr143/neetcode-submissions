class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int n0 = 0;
        int tot = 1;
        for(auto it : nums)
        {
            if(it == 0) n0++;
            else tot *= it;
        }
        if(n0>=2)
        {
            for(int i =0;i<n;i++)
            {
                nums[i]=0;
            }
            return nums;
        }
        else if(n0==1)
        {
            for(int i =0;i<n;i++)
            {
                if(nums[i]==0)
                {
                    nums[i]=tot;
                }
                else
                {
                    nums[i]=0;
                }
            }
            return nums;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                nums[i] = tot/nums[i];
            }
            return nums;
        }
    }
};
