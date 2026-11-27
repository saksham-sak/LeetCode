
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;

        for (auto &item : items) {
            minPrice = min(minPrice, item[1]);
        }

        vector<int> reward(n, 1);

        // Calculate reward for each item type
        for (int i = 0; i < n; i++) {
            int factor = items[i][0];

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % factor == 0) {
                    reward[i]++;
                }
            }
        }

        // 0/1 Knapsack DP
        const int NEG = -1000000000;
        vector<int> dp(budget + 1, NEG);

        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int price = items[i][1];

            for (int b = budget; b >= price; b--) {
                if (dp[b - price] != NEG) {
                    dp[b] = max(dp[b],
                                dp[b - price] + reward[i]);
                }
            }
        }

        int ans = 0;

        // Use remaining budget to buy cheapest items
        for (int cost = 0; cost <= budget; cost++) {
            if (dp[cost] == NEG) {
                continue;
            }

            int remaining = budget - cost;

            int total = dp[cost] + remaining / minPrice;

            ans = max(ans, total);
        }

        return ans;
    }
};

