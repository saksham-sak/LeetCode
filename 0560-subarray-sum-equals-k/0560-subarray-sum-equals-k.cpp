class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int countOut = 0;
        int n = nums.size();
        vector<int> result(n,0);
        int current = 0;

        for(int i = 0; i < n; i++) {
            current += nums[i];
            result[i] = current;
        }
        
        unordered_map<int,int> m;

        for(int j = 0;j < n;j++){
            int remain = result[j] - k;
            if(result[j] == k){
                countOut++;
            }
            if(m.find(remain) != m.end()){
                countOut +=  m[remain];
            }

            m[result[j]]++;
        }

        return countOut;
    }
};