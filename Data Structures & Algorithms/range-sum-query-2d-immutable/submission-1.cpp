class NumMatrix {
public:
    vector<vector<int>> sr;

    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        sr.resize(n+1, vector<int>(m+1,0));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                sr[i][j] = matrix[i-1][j-1]
                         + sr[i-1][j]
                         + sr[i][j-1]
                         - sr[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {

        row1++;
        col1++;
        row2++;
        col2++;

        return sr[row2][col2]
             - sr[row1-1][col2]
             - sr[row2][col1-1]
             + sr[row1-1][col1-1];
    }
};