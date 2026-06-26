class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = strs[0];
        int k = pre.size(),n=strs.size();
        for(int i=1;i<n;i++)
        {
            int j=0;
            while(j<k && j<strs[i].size() && pre[j]==strs[i][j])
            {
                j++;
            }
            k = j;
        }
        return pre.substr(0,k);
    }
};