class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans;


        while(low <= high){
            int mid = low + (high - low) / 2;
            int sum = 0;

            for(auto num : nums){
                if(num % mid == 0){
                    sum += num / mid;
                }
                else{
                    sum += (num / mid) + 1;
                }

            }

            if(sum <= threshold){
                ans = mid;
                high = mid - 1;

            }
            else{
                low = mid + 1;
            }

        }

        return ans;


    }
};