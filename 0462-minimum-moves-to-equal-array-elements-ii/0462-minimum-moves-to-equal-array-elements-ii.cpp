class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int median  = nums[n / 2];
        int count = 0;

        for(auto num : nums){
            count += abs(num - median);
        }

        return count;
    }
};