class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> freeroom;

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> busy;

        vector<long long> cnt(n,0);

        for(int i=0;i<n;i++)
        {
            freeroom.push(i);
        }
        for(auto it : meetings)
        {
            long long start = it[0];
            long long end = it[1];
            long long duration = end - start;

            while(!busy.empty() && busy.top().first < start)
            {
                freeroom.push(busy.top().second);
                busy.pop();
            }

            if(!freeroom.empty())
            {
                int room = freeroom.top();
                freeroom.pop();
                busy.push({end,room});
                cnt[room]++;
            }
            else
            {
                auto it = busy.top();
                busy.pop();

                int newend = it.first + duration;
                busy.push({newend,it.second});
                cnt[it.second]++;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(cnt[i]>cnt[ans])
            {
                ans = i;
            }
        }
        return ans;
        
    }
};