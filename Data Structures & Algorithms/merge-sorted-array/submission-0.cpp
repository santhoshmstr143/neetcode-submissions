class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m-1, r = n-1;
        int i = nums1.size()-1;
        while(l>=0 && r>=0)
        {
            if(nums1[l]>nums2[r])
            {
                nums1[i]=nums1[l];
                l--;
            }
            else
            {
                nums1[i]=nums2[r];
                r--;
            }
            i--;
        }
        while(l>=0)
        {
            nums1[i]=nums1[l];
            i--;
            l--;
        }
        while(r>=0)
        {
            nums1[i]=nums2[r];
            r--;
            i--;
        }
    }
};