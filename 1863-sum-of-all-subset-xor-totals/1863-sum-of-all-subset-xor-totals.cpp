
class Solution {
public:
    int ans = 0;

    void solve(int index, vector<int>& nums, int currentXor) {

        if (index == nums.size()) {
            ans += currentXor;
            return;
        }

        // Include current element
        solve(index + 1, nums, currentXor ^ nums[index]);

        // Exclude current element
        solve(index + 1, nums, currentXor);
    }

    int subsetXORSum(vector<int>& nums) {
        solve(0, nums, 0);
        return ans;
    }
};
