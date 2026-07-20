class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int time = 0;
        queue<pair<int,int>> q;
        int n = grid.size();
        int m= grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) 
                {
                    fresh++;
                }
                else if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};

        while(!q.empty() && fresh > 0)
        {
            int l = q.size();
            for(int s=0;s<l;s++)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(int k=0;k<4;k++)
                {
                    int x = i+ dx[k];
                    int y = j + dy[k];
                    if(x<0 || y<0 || x>=n || y>=m || grid[x][y]!=1) continue;
                    grid[x][y]=2;
                    q.push({x,y});
                    fresh--;
                }
            }
            time++;
        }
        return (fresh==0)? time : -1;
    }
};
