class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n+1,false);
        for(auto x : nums)
        {
            if(x>0 && x<=n) seen[x]=true;
        }
        for(int i=1;i<=n;i++)
        {
            if(!seen[i]) return i;
        }
        return n+1;
    }
};