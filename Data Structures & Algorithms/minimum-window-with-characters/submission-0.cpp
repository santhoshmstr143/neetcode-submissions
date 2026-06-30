class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m>n) return "";
        unordered_map<char,int> freq;
        for(auto ch : t)
        {
            freq[ch]++;
        }
        int l = 0,cnt = 0;
        int mn = INT_MAX;
        int start = 0;
        for(int r=0;r<n;r++)
        {
            if(freq[s[r]]>0) cnt++;
            freq[s[r]]--;
            while(cnt == t.size())
            {
                freq[s[l]]++;
                if(mn > r-l+1)
                {
                    mn = r-l+1;
                    start = l;
                }
                if(freq[s[l]]>0)
                {
                    cnt--;
                }
                l++;
            }
        }
        if(mn == INT_MAX)
            return "";

        return s.substr(start,mn);
    }
};
