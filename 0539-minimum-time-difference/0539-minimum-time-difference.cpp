class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> nums;

        // Convert time into minutes
        for(auto time : timePoints) {
            int hours = stoi(time.substr(0, 2));
            int minutes = stoi(time.substr(3, 2));

            nums.push_back(hours * 60 + minutes);
        }

        // Sort the minutes
        sort(nums.begin(), nums.end());

        int ans = INT_MAX;
        int n = nums.size();

        // Calculate adjacent differences
        for(int i = 1; i < n; i++) {
            ans = min(ans, nums[i] - nums[i - 1]);
        }

        // Circular difference
        ans = min(ans, 1440 - nums[n - 1] + nums[0]);

        return ans;
    }
};