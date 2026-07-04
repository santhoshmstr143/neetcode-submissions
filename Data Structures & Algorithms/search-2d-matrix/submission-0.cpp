class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(),m = matrix[0].size();
        int l = 0,r = n-1;
        int idx = -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(matrix[mid][0]<=k)
            {
                idx = mid;
                l = mid + 1;
            }
            else r = mid-1;
        }
        if(idx==-1) return false;
        l = 0;
        r = m-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(matrix[idx][mid]==k)
            {
                return true;
            }
            else if(matrix[idx][mid]>k)
            {
                r = mid-1;
            }
            else l=mid+1;
        }
        return false;
    }
};
