class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int,int> storeCount;

        for(auto num : nums){
            storeCount[num]++;
        }

        for(auto &[num,count] : storeCount){
            if(count > n/3){
                result.push_back(num);
            }
        }

        return result;
        
    }
};