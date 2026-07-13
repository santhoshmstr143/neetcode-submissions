class Solution {
public:
    int power(char ch)
    {
        if(ch=='I')
        {
            return 1;
        }
        else if(ch=='V')
        {
            return 5;
        }
        else if(ch=='X')
        {
            return 10;
        }
        else if(ch=='L') return 50;
        else if(ch=='C') return 100;
        else if(ch=='D') return 500;
        else if(ch == 'M') return 1000;
        else return -1;
    }
    int romanToInt(string s) {
        int n = s.size();
        int ans = power(s[n-1]);
        for(int i = n-2; i >= 0; i--)
        {
            int c = power(s[i]);
            if(power(s[i]) < power(s[i+1]))
            {
                c *= -1;
            }
            ans += c;
        }
        return ans;
    }
};