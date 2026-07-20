class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({i,j});
                }
            }
        }
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if(x<0 || y<0 || x>=n || y>=m || grid[x][y]!=2147483647) continue;
                
                grid[x][y]=1 + grid[i][j];
                q.push({x,y});
            }
        }
    }
};
