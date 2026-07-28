class Solution {
public:
    void expand(int l,int r,string &s,int &st,int &len)
    {
        while(l>=0 && r<s.size() && s[l]==s[r])
        {
            if(r-l+1 > len)
            {
                st = l;
                len = r-l+1;
            }
            r++;
            l--;
        }
    }
    string longestPalindrome(string s) {
        int st = 0;
        int len  = 1;
        for(int i=0;i<s.size();i++)
        {
            expand(i,i,s,st,len);
            expand(i,i+1,s,st,len);
        }
        return s.substr(st,len);
    }
};
