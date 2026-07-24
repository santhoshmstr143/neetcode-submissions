class Solution {
public:
    void solve(int i,vector<int> &temp,vector<vector<int>>&ans,vector<int> &nums)
    {
        if(i==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,temp,ans,nums);
        temp.pop_back();
        int j = i+1;
        while(j<nums.size() && nums[i]==nums[j]) j++;
        solve(j,temp,ans,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0,temp,ans,nums);
        return ans;
    }
};
