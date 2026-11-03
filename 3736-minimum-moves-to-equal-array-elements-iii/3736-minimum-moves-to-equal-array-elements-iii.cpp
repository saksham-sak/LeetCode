class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxValue = *max_element(nums.begin(),nums.end());
        int totalSum = accumulate(nums.begin(),nums.end(), 0);
        int expectedsum = maxValue * n;

        return expectedsum - totalSum;
    }
};