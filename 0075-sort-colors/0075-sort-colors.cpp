class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0,mid = 0,high = nums.size() - 1;


        while(mid <= high){

            // for zero 
            if(nums[mid] == 0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }

            // for ones
            else if(nums[mid] == 1){
                mid++;
            }

            // for tows
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }

    }
};