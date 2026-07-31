class Solution {
public:
    int total;
    int solve(int idx,int sum,vector<int> &stones,vector<vector<int>> &dp)
    {
        if(idx==stones.size())
        {
            int other = total - sum;
            return abs(other - sum);
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];

        int notpick = solve(idx+1,sum,stones,dp);
        int pick = solve(idx+1,sum+stones[idx],stones,dp);
        
        return dp[idx][sum] = min(pick,notpick);
    }

    int lastStoneWeightII(vector<int>& stones) {
        total = 0;
        for(auto it : stones) total += it;
        int n = stones.size();
        vector<vector<int>> dp(n,vector<int>(total+1,-1));
        return solve(0,0,stones,dp);
    }
};