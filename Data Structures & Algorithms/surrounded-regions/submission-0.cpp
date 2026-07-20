class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            {
                q.push({i,0});
                board[i][0]='#';
            }
            if(board[i][m-1]=='O')
            {
                q.push({i,m-1});
                board[i][m-1]='#';
            }
        }
        for(int i=1;i<m-1;i++)
        {
            if(board[0][i]=='O')
            {
                q.push({0,i});
                board[0][i]='#';
            }
            if(board[n-1][i]=='O')
            {
                q.push({n-1,i});
                board[n-1][i]='#';
            }
        }
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        while(!q.empty())
        {
            int i = q.front().first;
            int j  = q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if(x<0 || y <0 || x>=n || y>=m || board[x][y]!='O') continue;

                board[x][y] = '#';
                q.push({x,y});
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='#') board[i][j]='O';
            }
        }

    }
};
