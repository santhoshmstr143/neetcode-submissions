class Solution {
public:

    int expand(int l,int r,string &s)
    {
        int cnt = 0;

        while(l>=0 && r<s.size() && s[l]==s[r])
        {
            cnt++;
            l--;
            r++;
        }

        return cnt;
    }

    int countSubstrings(string s) {

        int ans = 0;

        for(int i=0;i<s.size();i++)
        {
            ans += expand(i,i,s);
            ans += expand(i,i+1,s);
        }

        return ans;
    }
};