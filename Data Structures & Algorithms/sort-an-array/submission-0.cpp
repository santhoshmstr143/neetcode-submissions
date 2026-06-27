class Solution {
public:
    void merge(int low,int m,int high,vector<int> &nums)
    {
        int l = low;
        int r = m + 1;
        vector<int> temp;
        while(l<=m && r<=high)
        {
            if(nums[l]<nums[r])
            {
                temp.push_back(nums[l]);
                l++;
            }
            else
            {
                temp.push_back(nums[r]);
                r++;
            }
        }
        while(l<=m)
        {
            temp.push_back(nums[l]);
            l++;
        }
        while(r<=high)
        {
            temp.push_back(nums[r]);
            r++;
        }
        for(int i=low;i<=high;i++)
        {
            nums[i] = temp[i-low];
        }
    }
    void mergesort(int low,int high,vector<int> &nums)
    {
        if(low>=high) return;
        int m = (high+low)/2;
        mergesort(low,m,nums);
        mergesort(m+1,high,nums);
        merge(low,m,high,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(0,nums.size()-1,nums);
        return nums;
    }
};