class Solution {
public:
    bool solve(int i, vector<int> &nums,vector<int> &side,int len)
    {
        if(i==nums.size())
        {
            return side[0]==len && side[1]==len && side[2]==len && side[3]==len;
        }

        for(int k=0;k<4;k++)
        {
            if(side[k]+nums[i]>len) continue;

            side[k] += nums[i];
            if(solve(i+1,nums,side,len))
            {
                return true;
            }
            side[k] -= nums[i];
        }
        return false;
    }

    bool makesquare(vector<int>& a) {
        sort(a.rbegin(),a.rend());
        int sum = 0;
        for(auto it : a) sum += it;
        if(sum%4) return false;
        vector<int> side(4,0);
        return solve(0,a,side,sum/4);
    }
};