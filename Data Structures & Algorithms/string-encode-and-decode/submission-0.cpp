class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(auto s : strs)
        {
            for(int i =0;i<s.size();i++)
            {
                ans +='*';
                ans +=s[i];
            }
            ans += '|';
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> temp;
        string lol;
        int n = s.size();
        for(int i=0;i<n;i+=2)
        {
            if(s[i]=='*')
            {
                lol += s[i+1];
            }
            else
            {
                temp.push_back(lol);
                lol = "";
                i--;
            }
        }
        return temp;
    }
};
