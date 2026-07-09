class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n5 = 0,n10=0;
        for(auto it : bills)
        {
            if(it==5)
            {
                n5++;
            }
            else if(it == 10)
            {
                if(n5<1)
                {
                    return false;
                }
                n5--;
                n10++;
            }
            else if(it==20)
            {
                if(n5>=3)
                {
                    n5 -= 3;
                }
                else if(n5>0 && n10>0)
                {
                    n5--;
                    n10--;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};