class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int total = 0;
        for(auto it : nums)
        {
            total += it;
        }

        // Maximum subarray sum
        int sum = 0;
        int maxSum = INT_MIN;

        for(auto it : nums)
        {
            sum += it;
            maxSum = max(maxSum, sum);

            if(sum < 0)
                sum = 0;
        }

        // Minimum subarray sum
        sum = 0;
        int minSum = INT_MAX;

        for(auto it : nums)
        {
            sum += it;
            minSum = min(minSum, sum);

            if(sum > 0)
                sum = 0;
        }

        if(maxSum < 0) // if every element is neg total - minsum is 0
            return maxSum;

        return max(maxSum, total - minSum);
    }
};