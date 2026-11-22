class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int mul = INT_MIN;
        for(int i = 0;i < n;i++){
            int mul1 = 1;
            for(int j = i;j < n;j++){
                mul1 *= nums[j];
                mul = max(mul,mul1);

            }
        }

        return mul;
    }
};