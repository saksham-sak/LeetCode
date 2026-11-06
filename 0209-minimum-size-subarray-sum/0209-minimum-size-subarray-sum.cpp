
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        // Step 1: Build prefix sum
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int ans = INT_MAX;

        // Step 2: Try every starting index
        for(int i = 0; i < n; i++) {

            int required = prefix[i] + target;

            // Step 3: Binary search
            auto it = lower_bound(
                prefix.begin() + i + 1,
                prefix.end(),
                required
            );

            // Step 4: Calculate length
            if(it != prefix.end()) {
                int j = it - prefix.begin();

                ans = min(ans, j - i);
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
