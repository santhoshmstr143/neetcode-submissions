class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>> a;
        for(auto it : intervals)
        {
            a.push_back({it[1],it[0]});
        }
        sort(a.begin(),a.end());
        int cnt = 1;
        int last = a[0].first;
        for(int i=1;i<a.size();i++)
        {
            if(a[i].second >= last)
            {
                cnt++;
                last = a[i].first;
            }
        }
        return intervals.size()-cnt;
    }
};
