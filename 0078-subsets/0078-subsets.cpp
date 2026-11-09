class Solution {
public:
    void printSubset(vector<int>& nums, vector<int>& ans, int i,
                     vector<vector<int>>& result) {

        // Base case
        if (i == nums.size()) {
            result.push_back(ans);
            return;
        }

        // Pick the current element
        ans.push_back(nums[i]);
        printSubset(nums, ans, i + 1, result);

        // Backtrack
        ans.pop_back();

        // Not pick the current element
        printSubset(nums, ans, i + 1, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> result;

        printSubset(nums, ans, 0, result);

        return result;
    }
};