class Solution {
public:
    void printSubset(vector<int>& nums,vector<int>& ans,vector<vector<int>>& result,int i){
        if(i == nums.size()){
            result.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        printSubset(nums,ans,result,i + 1);
        ans.pop_back();

        int idx = i + 1;

        while(idx < nums.size() && nums[idx] == nums[idx - 1]){
            idx++;
        }

        printSubset(nums,ans,result,idx);
        

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> ans;

        printSubset(nums,ans,result,0);

        return result;
    }
};