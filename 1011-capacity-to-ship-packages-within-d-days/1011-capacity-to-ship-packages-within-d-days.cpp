class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        long long low = *max_element(weights.begin(), weights.end());
        long long high = accumulate(weights.begin(), weights.end(), 0LL);

        while (low < high) {

            long long mid = low + (high - low) / 2;

            int countDay = 1;
            long long total = 0;

            for (int weight : weights) {
                if (total + weight > mid) {
                    countDay++;
                    total = weight;
                }
                else {
                    total += weight;
                }
            }

            if (countDay <= days)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};