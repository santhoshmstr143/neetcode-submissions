class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dis(n+1,1e9);
        dis[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        while(!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d>dis[node]) continue;
            for(auto it : adj[node])
            {
                if(d+it.second < dis[it.first])
                {
                    dis[it.first]=d+it.second;
                    pq.push({dis[it.first],it.first});
                }
            }
        }
        int ans = -1;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==1e9) return -1;
            ans = max(ans,dis[i]);
        }
        return ans;
        
    }
};
