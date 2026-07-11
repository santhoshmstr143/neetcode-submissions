class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int> r,d;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R')
            {
                r.push(i);
            }
            else
            {
                d.push(i);
            }
        }
        while(!r.empty() && !d.empty())
        {
            int nr = r.front();
            r.pop();
            int nd = d.front();
            d.pop();
            if(nr <nd)
            {
                r.push(nr+n);
            }
            else
            {
                d.push(nd+n);
            }
        }
        if(r.empty())
        {
            return "Dire";
        }
        else
        {
            return "Radiant";
        }

    }
};