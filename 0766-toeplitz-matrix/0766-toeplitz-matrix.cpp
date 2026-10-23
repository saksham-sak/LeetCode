class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
    
    // Check every element starting from the second row and column
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            // Compare with the top-left neighbor
            if (matrix[i][j] != matrix[i - 1][j - 1]) {
                return false;
            }
        }
    }
    return true;
    }
};