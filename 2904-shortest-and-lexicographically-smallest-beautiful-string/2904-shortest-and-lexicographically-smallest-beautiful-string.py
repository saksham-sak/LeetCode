class Solution(object):
    def shortestBeautifulSubstring(self, s, k):
        ones = []

        # Store positions of all 1s
        for i in range(len(s)):
            if s[i] == '1':
                ones.append(i)

        # Not enough 1s
        if len(ones) < k:
            return ""

        ans = ""

        # Take every group of k consecutive 1s
        for i in range(len(ones) - k + 1):
            left = ones[i]
            right = ones[i + k - 1]

            candidate = s[left:right + 1]

            if ans == "" or len(candidate) < len(ans):
                ans = candidate
            elif len(candidate) == len(ans) and candidate < ans:
                ans = candidate

        return ans