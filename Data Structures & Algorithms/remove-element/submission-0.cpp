class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int r = n-1,i=0;
        while(i<=r)
        {
            if(nums[i]==val)
            {
                while(r>i && nums[r]==val)
                {
                    r--;
                }
                // if(i>r) break;
                swap(nums[i],nums[r]);
                r--;
            }
            else i++;
        }
        return r+1;
    }
};