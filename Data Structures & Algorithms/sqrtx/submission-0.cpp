class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int l = 1;
        int r = x;
        while(l<=r)
        {
            int mid = (l+r)/2;
            long long val =1LL* mid * mid;

            if(val==x) return mid;
            else if(val<x) l= mid+1;
            else r = mid-1;
        }
        return r;
    }
};