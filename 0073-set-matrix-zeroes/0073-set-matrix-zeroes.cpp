class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> index;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(matrix[i][j] == 0){
                    index.push_back({i,j});
                }
            }
        }

        for(auto arr: index){
            for (int j = 0; j < n; j++) {
                matrix[arr[0]][j] = 0;
            }

    // Make the column zero
           for (int i = 0; i < m; i++) {
                matrix[i][arr[1]] = 0;
            }
        }

    }
};