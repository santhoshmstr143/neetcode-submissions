class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l= 0,mx = 0;
        int maxf = 0;
        vector<int> freq(26,0);
        for(int r =0;r<n;r++)
        {
            freq[s[r]-'A']++;
            maxf = max(maxf,freq[s[r]-'A']);
            while((r-l+1)-maxf>k)
            {
                freq[s[l]-'A']--;
                l++;
            }
            mx = max(mx,r-l+1);
        }
        return mx;
    }
};
