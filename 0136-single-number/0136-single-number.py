class Solution(object):
    def singleNumber(self, nums):
        arr = list(set(nums))

        for num in arr:
            if(nums.count(num) == 1):
                return num
        