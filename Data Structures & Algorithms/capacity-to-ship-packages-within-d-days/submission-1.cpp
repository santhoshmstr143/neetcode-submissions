class Solution {
public:
    int possible(int mid, vector<int> &weights)
    {
        int cnt = 1;
        int sum = 0;
        for(auto it : weights)
        {
            if(sum + it > mid)
            {
                cnt++;
                sum = it;
            }
            else
            {
                sum += it;
            }
        }
        return cnt;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int r = accumulate(weights.begin(), weights.end(), 0);
        int l = *max_element(weights.begin(), weights.end());
        int ans = r;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int t = possible(mid,weights);
            if(t<=days)
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