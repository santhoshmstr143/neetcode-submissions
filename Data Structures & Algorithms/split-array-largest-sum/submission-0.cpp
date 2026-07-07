class Solution {
public:
    bool possible(int mid,int k,vector<int> &nums)
    {
        int arr = 1,sum = 0;
        for(int it : nums)
        {
            sum+= it;
            if(sum > mid)
            {
                arr++;
                if(arr>k) return false;
                sum=it;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(),nums.end());
        int r = accumulate(nums.begin(),nums.end(),0);
        int ans = r;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(possible(mid,k,nums))
            {
                ans = mid;
                r = mid -1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};