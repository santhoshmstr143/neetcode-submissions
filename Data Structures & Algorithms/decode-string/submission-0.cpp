class Solution {
public:
    string decodeString(string s) {
        stack<int> numst;
        stack<string> strst;

        int num = 0;
        string cur = "";
        for(auto ch : s)
        {
            if(isdigit(ch))
            {
                num = num *10 + (ch-'0');
            }
            else if(ch=='[')
            {
                numst.push(num);
                strst.push(cur);
                num = 0;
                cur = "";
            }
            else if(ch == ']')
            {
                int k = numst.top();
                numst.pop();
                string prev = strst.top();
                strst.pop();
                while(k--)
                {
                    prev += cur;
                }
                cur = prev;
            }
            else
            {
                cur += ch;
            }
        }
        return cur;
    }
};