class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = high;
        

        while(low <= high){
            int value = low + (high - low) / 2;

            long long hours = 0;

            for(auto banana : piles){
                hours += (banana + value - 1LL) / value;
            }

            if(hours <= h){
                ans = value;
                high = value - 1;
            }
            else{
                low = value + 1;
            }
        }

        return ans;

    }
};