class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = target[0];
        int y = target[1];
        int z = target[2];
        bool x1 = false;
        bool y1 = false;
        bool z1 = false;

        for(auto it : triplets)
        {
            if( it[0]<=x && it[1]<=y && it[2]<=z)
            {
                if(x==it[0]) x1 = true;
                if(y==it[1]) y1 = true;
                if(z==it[2]) z1 = true;
            }
        }
        return x1 && y1 && z1;
    }
};
