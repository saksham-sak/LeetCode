class Solution(object):
    def missingNumber(self, nums):
        length = len(nums)

        for i in range(length + 1):
            if i not in nums:
                return i

        