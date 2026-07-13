class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        int f = 1;
        if(n<0)
        {
            f = 0;
            n = -n;
        }
        while(n)
        {
            if(n%2==1)
            {
                ans *= x;
                n--;
                continue;
            }
            x *= x;
            n /= 2;
        }
        return (f==1)? ans : 1/ans;
    }
};
