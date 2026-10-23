class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < n;i++){
            vector <int> ans1;
            for(int j = 0;j < m;j++){
                ans1.push_back(matrix[j][i]);
            }
            ans.push_back(ans1);
        }

        return ans;
    }
};