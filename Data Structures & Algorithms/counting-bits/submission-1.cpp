class Solution {
public:
    int solve(int n)
    {
        int ans = 0;
        while(n)
        {
            int r = n%2;
            n = n/2;
            ans += r;
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1,-1);
        for(int i=0;i<=n;i++)
        {
            if(i%2==0 && ans[i/2]!= -1)
            {
                ans[i] = ans[i/2];
            }
            else
            {
                ans[i] = solve(i);
            }
        }
        return ans;
    }
};
