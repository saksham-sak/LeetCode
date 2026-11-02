class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid = 0;

        while(mid < high){

            if(nums[mid] % 2 != 0){
                swap(nums[mid],nums[high]);
                high--;

            }
            else{
                mid++;
            }

        }
        return nums;
    }
};