class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n0 = 0,n1=0,n2=0;
        for(auto it : nums)
        {
            if(it == 0) n0++;
            else if(it==1) n1++;
            else if(it==2) n2++;
        }
        for(int i=0;i<n0;i++)
        {
            nums[i]=0;
        }
        for(int i=n0;i<n0+n1;i++)
        {
            nums[i]=1;
        }
        for(int i=n1+n0;i<n0+n1+n2;i++)
        {
            nums[i]=2;
        }
    }
};