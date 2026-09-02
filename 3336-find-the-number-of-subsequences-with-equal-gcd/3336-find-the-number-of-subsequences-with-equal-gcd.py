class Solution(object):
    def subsequencePairCount(self, nums):
        MOD = 10**9 + 7
        MAX = 200

        dp = [[0] * (MAX + 1) for _ in range(MAX + 1)]
        dp[0][0] = 1

        for x in nums:
            new_dp = [[0] * (MAX + 1) for _ in range(MAX + 1)]

            for g1 in range(MAX + 1):
                for g2 in range(MAX + 1):

                    if dp[g1][g2] == 0:
                        continue

                    ways = dp[g1][g2]

                    # 1. Don't use x
                    new_dp[g1][g2] += ways

                    # 2. Put x into seq1
                    ng1 = gcd(g1, x)
                    new_dp[ng1][g2] += ways

                    # 3. Put x into seq2
                    ng2 = gcd(g2, x)
                    new_dp[g1][ng2] += ways

            dp = new_dp

        ans = 0

        for g in range(1, MAX + 1):
            ans += dp[g][g]
            ans %= MOD

        return ans