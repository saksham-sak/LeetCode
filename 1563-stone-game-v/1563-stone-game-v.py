class Solution:
    def stoneGameV(self, stoneValue):
        n = len(stoneValue)

        if n == 1:
            return 0

        dp = [[0] * n for _ in range(n)]

        # mx[i][j] stores the best value needed
        # to optimize transitions.
        mx = [[0] * n for _ in range(n)]

        for i in range(n):
            mx[i][i] = stoneValue[i]

        for j in range(1, n):

            mid = j
            sm = stoneValue[j]
            right = 0

            for i in range(j - 1, -1, -1):

                sm += stoneValue[i]

                # Move mid while left part <= right part
                while (right + stoneValue[mid]) * 2 <= sm:
                    right += stoneValue[mid]
                    mid -= 1

                # Equal sums
                if right * 2 == sm:
                    dp[i][j] = mx[i][mid]

                # Left side is smaller
                if mid != i:
                    dp[i][j] = max(
                        dp[i][j],
                        mx[i][mid - 1]
                    )

                # Right side is smaller
                if mid != j:
                    dp[i][j] = max(
                        dp[i][j],
                        mx[j][mid + 1]
                    )

                # Update auxiliary DP
                mx[i][j] = max(
                    mx[i][j - 1],
                    dp[i][j] + sm
                )

                mx[j][i] = max(
                    mx[j][i + 1],
                    dp[i][j] + sm
                )

        return dp[0][n - 1]
        