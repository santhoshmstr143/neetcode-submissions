class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        int n = a.size();
        int ans = 0, c = 0, s = -1;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
            {
                if(s==0)
                {
                    c++;
                }
                else c = 1;
                s = 1;
            }
            else if(a[i]<a[i+1])
            {
                if(s==1)
                {
                    c++;
                }
                else c = 1;
                s = 0;
            }
            else
            {
                c = 0;
                s = -1;
            }
            ans = max(ans,c);
        }
        return ans+1;
    }
};