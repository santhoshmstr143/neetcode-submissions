class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> pac(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) 
        {
            q.push({i,0});
            pac[i][0]=1;
        }
        for(int i=1;i<m;i++) 
        {
            q.push({0,i});
            pac[0][i]=1;
        }
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k=0;k<4;k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if(x<0 || y<0 || x>=n || y>=m || heights[x][y]<heights[i][j] || pac[x][y]==1) continue;

                q.push({x,y});
                pac[x][y]=1;                
            }
        }
        vector<vector<int>> at(n,vector<int>(m,0));
        for(int i=0;i<n;i++) 
        {
            q.push({i,m-1});
            at[i][m-1]=1;
        }
        for(int i=0;i<m-1;i++) 
        {
            q.push({n-1,i});
            at[n-1][i]=1;
        }
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k=0;k<4;k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if(x<0 || y<0 || x>=n || y>=m || heights[x][y]<heights[i][j] || at[x][y]==1) continue;

                q.push({x,y});
                at[x][y]=1;                
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(at[i][j]==1 && pac[i][j]==1)
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
