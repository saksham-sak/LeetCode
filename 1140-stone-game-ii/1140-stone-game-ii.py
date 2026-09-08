class Solution:
    def stoneGameII(self, piles):
        n = len(piles)

        # Suffix sum
        suffix = [0] * (n + 1)

        for i in range(n - 1, -1, -1):
            suffix[i] = suffix[i + 1] + piles[i]

        # dp[i][M] = maximum stones current player can get
        # starting from index i with M
        dp = [[0] * (n + 1) for _ in range(n)]

        def solve(i, M):
            # Can take all remaining piles
            if i >= n:
                return 0

            if 2 * M >= n - i:
                return suffix[i]

            if dp[i][M] != 0:
                return dp[i][M]

            best = 0

            for x in range(1, 2 * M + 1):
                next_M = max(M, x)

                # Current player gets:
                # total remaining - opponent's best
                current = suffix[i] - solve(i + x, next_M)

                best = max(best, current)

            dp[i][M] = best
            return best

        return solve(0, 1)