class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        if(hand.size()%k) return false;

        map<int,int> mp;
        for(auto it : hand) mp[it]++;

        while(!mp.empty())
        {
            auto [start,freq] = *mp.begin();
            for(int i=0;i<k;i++)
            {
                if(mp[i+start]==0) return false;
                mp[i+start]--;
                if(mp[i+start]==0) mp.erase(i+start);
            }
        }
        return true;
    }
};
