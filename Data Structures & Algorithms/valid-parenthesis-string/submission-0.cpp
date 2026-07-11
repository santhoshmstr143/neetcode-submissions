class Solution {
public:
    bool checkValidString(string s) {
        int l = 0, h = 0;
        for(char c : s)
        {
            if(c=='(')
            {
                h++;
                l++;
            }
            else if(c==')')
            {
                h--;
                l--;
            }
            else
            {
                l--;
                h++;
            }
            if(h<0) return false;
            l = max(l,0);
        }
        return l==0;
    }
};
