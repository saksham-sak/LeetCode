class Solution(object):
    def minimumDeletions(self, nums):
        n = len(nums)

        min_val = min(nums)
        max_val = max(nums)

        minIndex = nums.index(min_val)
        maxIndex = nums.index(max_val)

        left = min(minIndex, maxIndex)
        right = max(minIndex, maxIndex)

        # Both from left
        option1 = right + 1

        # Both from right
        option2 = n - left

        # Min from left, max from right OR vice versa
        option3 = (left + 1) + (n - right)

        return min(option1, option2, option3)
        