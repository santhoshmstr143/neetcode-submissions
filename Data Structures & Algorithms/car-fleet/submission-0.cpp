class Solution {
public:
    int carFleet(int des, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> car;
        int n = position.size();
        for(int i=0;i<n;i++)
        {
            car.push_back({position[i],speed[i]});
        }
        sort(car.begin(),car.end());
        int f = 0;
        double l = 0;
        for(int i=n-1;i>=0;i--)
        {
            double t = (double)(des-car[i].first)/car[i].second;
            if(t>l)
            {
                f++;
                l = t;
            }

        }
        return f;
    }
};
