class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;

        // Flatten 2D grid
        for(auto &row : grid) {
            nums.insert(nums.end(), row.begin(), row.end());
        }

        int n = nums.size();

        // Check feasibility
        for(int i = 1; i < n; i++) {
            if((nums[i] - nums[0]) % x != 0) {
                return -1;
            }
        }

        // Find median without fully sorting
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());

        int median = nums[n / 2];
        int count = 0;

        // Calculate minimum operations
        for(auto num : nums) {
            count += abs(num - median) / x;
        }

        return count;
    }
};