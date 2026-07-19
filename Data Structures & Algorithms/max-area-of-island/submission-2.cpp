class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int dfs(int i,int j,vector<vector<int>> &grid)
    {
        int n = grid.size(),m = grid[0].size();
        int a = 1;
        grid[i][j]=0;
        for(int k=0;k<4;k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if(x<0 || x>=n || y<0 || y>=m) continue;
            if(grid[x][y]==1)
            {
                a += dfs(x,y,grid);
            }
        }
        return a;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int area = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    area = max(dfs(i,j,grid),area);
                }
            }
        }
        return area;
    }
};
