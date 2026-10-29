class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> freq;

        for(auto num : nums){
            freq[num]++;
        }

        for(auto p : freq){
            if(p.second == 2){
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};