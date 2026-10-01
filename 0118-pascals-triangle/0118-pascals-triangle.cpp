class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i = 0;i < numRows;i++){
            if(i == 0){
                ans.push_back({1});
            }
            else if(i == 1){
                ans.push_back({1,1});
            }
            else{
               vector<int> suma = {1};
                for(int j = 0;j < ans[i - 1].size() - 1;j++){
                    int dob = ans[i-1][j] + ans[i-1][j + 1];
                    suma.push_back(dob);
                }
                suma.push_back(1);
                ans.push_back(suma);
            }
        }

        return ans;
    }
};