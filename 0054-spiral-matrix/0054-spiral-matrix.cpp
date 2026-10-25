
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;

        int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;

        while (srow <= erow && scol <= ecol) {

            // 1. Left to right
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(matrix[srow][j]);
            }

            // 2. Top to bottom
            for (int i = srow + 1; i <= erow; i++) {
                ans.push_back(matrix[i][ecol]);
            }

            // 3. Right to left
            for (int j = ecol - 1; j >= scol; j--) {
                if (srow == erow) break;
                ans.push_back(matrix[erow][j]);
            }

            // 4. Bottom to top
            for (int i = erow - 1; i > srow; i--) {
                if (scol == ecol) break;
                ans.push_back(matrix[i][scol]);
            }

            // Shrink boundaries
            srow++;
            scol++;
            erow--;
            ecol--;
        }

        return ans;
    }
};
