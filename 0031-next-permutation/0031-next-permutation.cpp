class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        int n = nums.size() - 1;  

        for(int i = n - 1;i >= 0;i--){
            if(nums[i] < nums[i + 1]){
                pivot = i;
                break;
            }
        }
        if(pivot == -1){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(int i = n;i > pivot;i--){
                if(nums[pivot] < nums[i]){
                    swap(nums[pivot],nums[i]);
                    break;
                }
            }

            reverse(nums.begin() + pivot + 1, nums.end());
        }
    }
};