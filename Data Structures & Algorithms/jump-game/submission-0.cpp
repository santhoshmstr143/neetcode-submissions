class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int mxi = 0;
        for(int i=0;i<n;i++)
        {
            if(mxi==n-1) return true;
            if(i==mxi && nums[i]==0) return false;
            mxi = max(mxi,i+nums[i]);
        }
        return true;
    }
};
