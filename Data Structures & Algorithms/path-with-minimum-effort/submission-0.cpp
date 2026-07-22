class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        while(!pq.empty())
        {
            auto vec = pq.top();
            pq.pop();
            int d = vec[0];
            int i = vec[1];
            int j = vec[2];
            if(d > dis[i][j]) continue;
            for(int k = 0;k<4;k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if(x<0 || y<0 || x>=n || y>=m) continue;
                int t = max(d,abs(heights[i][j]-heights[x][y]));
                if(t<dis[x][y])
                {
                    dis[x][y]=t;
                    pq.push({t,x,y});
                }
            }
        }
        return dis[n-1][m-1];
    }
};