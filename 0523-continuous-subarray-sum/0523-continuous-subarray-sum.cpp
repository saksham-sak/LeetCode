class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long current = 0;
        long long mod = abs((long long)k);

        unordered_map<long long, int> ans;
        ans[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            current += nums[i];

            long long key;

            if (k == 0) {
                key = current;
            } 
            else {
                key = ((current % mod) + mod) % mod;
            }

            if (ans.find(key) != ans.end()) {
                if (i - ans[key] >= 2) {
                    return true;
                }
            } 
            else {
                ans[key] = i;
            }
        }

        return false;
    }
};
