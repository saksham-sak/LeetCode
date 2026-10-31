class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        int current = 0;



        unordered_map<int,int> ans;
        ans[0] = 1;

        for(int i = 0;i < n;i++){
            current += nums[i];


            int reminder = ((current % k) + k) % k;

            if(ans.find(reminder) != ans.end()){
                count += ans[reminder];
            }else{
                ans[reminder] = 0;
            }
            ans[reminder]++;

        }
        return count;
    }
};