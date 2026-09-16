class Solution:
    def numberOfSets(self, n, k):
        MOD = 1000000007

        dp = [[0] * (k + 1) for _ in range(n + 1)]

        # 0 segments -> 1 way
        for i in range(n + 1):
            dp[i][0] = 1

        for j in range(1, k + 1):
            prefix = 0

            for i in range(1, n + 1):

                # A segment needs at least 2 points
                if i >= 2:
                    prefix = (prefix + dp[i - 1][j - 1]) % MOD

                dp[i][j] = (dp[i - 1][j] + prefix) % MOD

        return dp[n][k]