class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;

        m[0] = -1;

        int sum = 0;
        int maxLength = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 0)
                sum--;
            else
                sum++;

            if(m.find(sum) != m.end()) {
                maxLength = max(maxLength, i - m[sum]);
            }
            else {
                m[sum] = i;
            }
        }

        return maxLength;
    }
};