class Solution {
public:
    int possible(vector<int> &a,int k)
    {
        int hour = 0;
        for(auto it : a)
        {
            hour += ceil((double)it/k);
        }
        return hour;
    }
    int minEatingSpeed(vector<int>& a, int h) {
        int l = 1;
        int r = *max_element(a.begin(),a.end());
        int ans = r;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int t = possible(a,mid);
            if(t<=h)
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans;
    }
};
