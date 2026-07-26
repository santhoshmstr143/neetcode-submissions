class Solution {
public:
    string addBinary(string a, string b) {

        int n = a.size() - 1;
        int m = b.size() - 1;

        int carry = 0;
        string ans;

        while(n >= 0 && m >= 0)
        {
            int sum = (a[n]-'0') + (b[m]-'0') + carry;

            ans += (sum % 2) + '0';

            carry = sum / 2;

            n--;
            m--;
        }

        while(n >= 0)
        {
            int sum = (a[n]-'0') + carry;

            ans += (sum % 2) + '0';

            carry = sum / 2;

            n--;
        }

        while(m >= 0)
        {
            int sum = (b[m]-'0') + carry;

            ans += (sum % 2) + '0';

            carry = sum / 2;

            m--;
        }

        if(carry)
            ans += '1';

        reverse(ans.begin(), ans.end());

        return ans;
    }
};