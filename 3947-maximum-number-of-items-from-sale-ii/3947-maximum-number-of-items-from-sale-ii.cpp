
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // Step 1: Find maximum factor and minimum price
        int maxFactor = 0;
        int minPrice = INT_MAX;

        for (auto &item : items) {
            maxFactor = max(maxFactor, item[0]);
            minPrice = min(minPrice, item[1]);
        }

        // Step 2: Count frequency of each factor
        vector<int> freq(maxFactor + 1, 0);

        for (auto &item : items) {
            freq[item[0]]++;
        }

        // Step 3: Count how many items each factor can unlock
        for (int i = 1; i <= maxFactor; i++) {
            for (int j = i * 2; j <= maxFactor; j += i) {
                freq[i] += freq[j];
            }
        }

        // Step 4: Sort items by price
        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long ans = 0;
        long long remaining = budget;

        // Step 5: Buy valuable copies first
        for (auto &item : items) {
            int factor = item[0];
            int price = item[1];

            // No benefit compared with buying cheapest items
            if (price >= 2LL * minPrice) {
                break;
            }

            // Number of free copies available
            int gain = freq[factor] - 1;

            // Maximum boosted purchases
            long long take = min(
                (long long)gain,
                remaining / price
            );

            ans += take * 2;
            remaining -= take * price;
        }

        // Step 6: Spend remaining budget on cheapest items
        ans += remaining / minPrice;

        return (int)ans;
    }
};
