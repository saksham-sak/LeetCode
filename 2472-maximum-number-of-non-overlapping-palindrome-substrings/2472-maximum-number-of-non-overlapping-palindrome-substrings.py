class Solution(object):
    def maxPalindromes(self, s, k):
        n = len(s)

        palindrome = [[False] * n for _ in range(n)]

        for length in range(1, n + 1):
            for left in range(n - length + 1):
                right = left + length - 1

                if s[left] == s[right]:
                    if length <= 2:
                        palindrome[left][right] = True
                    else:
                        palindrome[left][right] = palindrome[left + 1][right - 1]

        dp = [0] * (n + 1)

        for i in range(1, n + 1):
            dp[i] = dp[i - 1]

            for j in range(i - k + 1):
                if palindrome[j][i - 1]:
                    dp[i] = max(dp[i], dp[j] + 1)

        return dp[n]