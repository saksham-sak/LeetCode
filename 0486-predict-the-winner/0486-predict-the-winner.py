class Solution:
    def predictTheWinner(self, nums):
        n = len(nums)
        dp = nums[:]

        for length in range(2, n + 1):
            for l in range(n - length + 1):
                r = l + length - 1

                dp[l] = max(
                    nums[l] - dp[l + 1],
                    nums[r] - dp[l]
                )

        return dp[0] >= 0
        