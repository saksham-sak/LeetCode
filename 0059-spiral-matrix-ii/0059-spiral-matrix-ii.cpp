class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int i = 1,srow = 0, scol = 0, erow = n - 1, ecol = n - 1;

        while(srow <= erow && scol <= ecol){
            for(int j = scol;j <= ecol;j++){
                ans[srow][j] = i;
                i++;
            }

            for(int j = srow + 1;j <= erow;j++){
                ans[j][ecol] = i;
                i++;
            }

            for(int j = ecol - 1;j >= scol;j--){
                if(srow == erow){
                    break;
                }
                ans[erow][j] = i;
                i++;
            }

            for(int j = erow - 1;j >= srow + 1;j--){
                if(scol == ecol){
                    break;
                }
                ans[j][scol] = i;
                i++;
            }

            srow++;
            erow--;
            scol++;
            ecol--;
        }



        return ans;
    }
    
};