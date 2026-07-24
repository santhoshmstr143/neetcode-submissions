class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    bool solve(int ind, int i, int j, vector<vector<char>> &a, string &word)
    {
        int n = a.size();
        int m = a[0].size();

        if(a[i][j] != word[ind]) return false;

        if(ind == word.size() - 1) return true;

        char ch = a[i][j];
        a[i][j] = '#';

        for(int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if(x < 0 || y < 0 || x >= n || y >= m || a[x][y] == '#')
                continue;

            if(solve(ind + 1, x, y, a, word))
            {
                a[i][j] = ch;
                return true;
            }
        }

        a[i][j] = ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == word[0])
                {
                    if(solve(0, i, j, board, word))
                        return true;
                }
            }
        }

        return false;
    }
};