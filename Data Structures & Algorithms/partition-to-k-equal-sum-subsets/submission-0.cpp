class Solution {
    int target, n;
    vector<int> dp;

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) return false;

        target = total / k;
        n = nums.size();
        dp.assign(1 << n, -1);
        sort(nums.rbegin(), nums.rend());
        return backtrack(nums, 0, k, 0, (1 << n) - 1);
    }

private:
    int backtrack(vector<int>& nums, int i, int k, int subsetSum, int mask) {
        if (dp[mask] != -1) return dp[mask];
        if (k == 0) {
            dp[mask] = 1;
            return 1;
        }
        if (subsetSum == target) {
            dp[mask] = backtrack(nums, 0, k - 1, 0, mask);
            return dp[mask];
        }
        for (int j = i; j < nums.size(); j++) {
            if ((mask & (1 << j)) == 0 || subsetSum + nums[j] > target) continue;
            if (backtrack(nums, j + 1, k, subsetSum + nums[j], mask ^ (1 << j))) {
                dp[mask] = 1;
                return 1;
            }
            if (subsetSum == 0) {
                break;
            }
        }
        dp[mask] = 0;
        return 0;
    }
};