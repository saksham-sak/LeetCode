class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        int n = nums.size();
        int currentSum = 0;
        unordered_map<int,int> ans;

        ans[0] = 1;

        for(int i = 0;i < n;i++){
            currentSum += nums[i];
            int remain = currentSum - goal;

            if(ans.find(remain) != ans.end()){
                count += ans[remain];
            }

            ans[currentSum]++;
    
        }
            
        return count;
    }
};