class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat.size();

        for(int i = 0;i < n;i++){
            int j = n - i - 1;
            sum += mat[i][i];
            if(i != j){
                sum += mat[i][j];
            }

        }

        return sum;
    }
};