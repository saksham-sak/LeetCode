class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;

        for(auto &row : grid) {
            nums.insert(nums.end(), row.begin(), row.end());
        }

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i = 0; i < n - 1; i++) {
            if((nums[i + 1] - nums[i]) % x != 0) {
                return -1;
            }
        }

        int median = nums[n / 2];
        int count = 0;

        for(auto num : nums) {
            count += abs(num - median) / x;
        }

        return count;
    }
};