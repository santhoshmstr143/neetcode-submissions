class Solution {
public:
    string mergeAlternately(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        int r = 0,l = 0;
        int f = 1;
        string ans;
        while(r<n1 && l<n2)
        {
            if(f)
            {
                ans += s[r];
                r++;
            }
            else
            {
                ans += t[l];
                l++;
            }
            f = 1 - f;
        }
        while(r<n1)
        {
            ans += s[r];
            r++;
        }
        while(l<n2)
        {
            ans += t[l];
            l++;
        }
        return ans;
    }
};