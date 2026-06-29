class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        if(m > n)
            return false;

        vector<int> freq(26,0);

        for(char c : s1)
            freq[c-'a']++;
        
        int l = 0;
        for(int r=0;r<n;r++)
        {
            freq[s2[r]-'a']--;
            while(freq[s2[r]-'a']<0)
            {
                freq[s2[l]-'a']++;
                l++;
            }
            if(r-l+1==m) return true;
        }
        return false;
    }
};
