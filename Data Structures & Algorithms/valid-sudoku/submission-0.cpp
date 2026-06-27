class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& a) {

        int n = 9;
        for(int i=0;i<n;i++)
        {
            vector<bool> vis(9,false);
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='.') continue;
                int x = a[i][j]-'1';
                if(vis[x]) return false;
                vis[x]=true;
            }
        }

        for(int i=0;i<n;i++)
        {
            vector<bool> vis(9,false);
            for(int j=0;j<n;j++)
            {
                if(a[j][i]=='.') continue;
                int x = a[j][i]-'1';
                if(vis[x]) return false;
                vis[x]=true;
            }
        }

        for(int r=0;r<9;r+=3)
        {
            for(int c=0;c<9;c+=3)
            {
                vector<bool> vis(9,false);
                for(int i=r;i<r+3;i++)
                {
                    for(int j=c;j<c+3;j++)
                    {
                        if(a[i][j]=='.') continue;
                        int x = a[i][j]-'1';
                        if(vis[x]) return false;
                        vis[x]=true;
                    }
                }
            }
        }

        return true;
    }
};