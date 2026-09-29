class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int len = m + n - 1;

        // Valid parentheses string must have even length
        if (len % 2 == 1)
            return false;

        // dp[j][balance]
        vector<vector<bool>> dp(n, vector<bool>(len + 1, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // New states for this cell
                vector<bool> next(len + 1, false);

                // Starting cell
                if (i == 0 && j == 0) {
                    if (grid[i][j] == '(')
                        next[1] = true;

                    dp[j] = next;
                    continue;
                }

                // Take states from TOP
                if (i > 0) {
                    for (int balance = 0; balance <= len; balance++) {
                        if (dp[j][balance]) {
                            int newBalance =
                                balance + (grid[i][j] == '(' ? 1 : -1);

                            if (newBalance >= 0 &&
                                newBalance <= len) {
                                next[newBalance] = true;
                            }
                        }
                    }
                }

                // Take states from LEFT
                if (j > 0) {
                    for (int balance = 0; balance <= len; balance++) {
                        if (dp[j - 1][balance]) {
                            int newBalance =
                                balance + (grid[i][j] == '(' ? 1 : -1);

                            if (newBalance >= 0 &&
                                newBalance <= len) {
                                next[newBalance] = true;
                            }
                        }
                    }
                }

                // Store ONLY the states of this cell
                dp[j] = next;
            }
        }

        // Final balance must be 0
        return dp[n - 1][0];
    }
};