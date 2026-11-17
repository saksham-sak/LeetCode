
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, 1e9));

        // Precompute semi-palindrome conversion costs
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {

                int len = r - l + 1;

                for (int d = 1; d < len; d++) {

                    if (len % d != 0)
                        continue;

                    int changes = 0;

                    for (int rem = 0; rem < d; rem++) {

                        int left = l + rem;
                        int right = l + rem +
                            ((len - 1 - rem) / d) * d;

                        while (left < right) {

                            if (s[left] != s[right])
                                changes++;

                            left += d;
                            right -= d;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        // Dynamic Programming
        const int INF = 1e9;

        vector<vector<int>> dp(n + 1,
                               vector<int>(k + 1, INF));

        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {

            for (int i = 1; i <= n; i++) {

                for (int p = 0; p < i; p++) {

                    if (dp[p][parts - 1] == INF)
                        continue;

                    if (i - p < 2)
                        continue;

                    dp[i][parts] = min(
                        dp[i][parts],
                        dp[p][parts - 1] + cost[p][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};

