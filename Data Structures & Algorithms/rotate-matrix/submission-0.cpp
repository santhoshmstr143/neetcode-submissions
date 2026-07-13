class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(matrix[j][i],matrix[i][j]);
            }
        }
        return matrix;
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n/2;i++)
        {
            for(int j=0;j<n;j++)
            {
                swap(matrix[i][j],matrix[n-1-i][j]);
            }
        }
        transpose(matrix);
    }
};
