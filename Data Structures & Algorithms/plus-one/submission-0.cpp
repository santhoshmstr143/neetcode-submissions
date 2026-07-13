class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n = digits.size();
        int c = 1;
        for(int i=n-1;i>=0;i--)
        {
            int k = digits[i];
            k = k + c;
            c = k/10;
            ans.push_back(k%10);
        }
        if(c)
            ans.push_back(c);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
