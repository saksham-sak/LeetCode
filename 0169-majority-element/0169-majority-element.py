class Solution(object):
    def majorityElement(self, nums):
        arr = list(set(nums))
        for num in arr:
            if nums.count(num) > len(nums) / 2:
                return num
        