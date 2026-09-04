class Solution:
    def longestSubsequence(self, nums):
        n = len(nums)

        xor = 0
        has_non_zero = False

        for num in nums:
            xor ^= num

            if num != 0:
                has_non_zero = True

        if xor != 0:
            return n

        if has_non_zero:
            return n - 1

        return 0
        
        