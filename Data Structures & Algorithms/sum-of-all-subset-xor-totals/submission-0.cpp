class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int xr = 0;
        for(auto it : nums) xr |= it;

        return xr * (1 << (nums.size()-1));
    }
};