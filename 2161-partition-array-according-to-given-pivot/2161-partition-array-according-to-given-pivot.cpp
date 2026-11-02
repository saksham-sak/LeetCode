class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller,equal,greater;
        int n = nums.size();
        for(auto x:nums){
            if(x < pivot){
                smaller.push_back(x);
            }
            else if(x == pivot){
                equal.push_back(x);
            }
            else{
                greater.push_back(x);
            }
        }
        nums.clear();
        nums.insert(nums.end(), smaller.begin(), smaller.end());
        nums.insert(nums.end(), equal.begin(), equal.end());
        nums.insert(nums.end(), greater.begin(), greater.end());
        return nums;
    }
};