class Solution(object):
    def singleNumber(self, nums):
        sumOfnums = sum(nums)
        newNums = list(set(nums))
        sumofnew = sum(newNums) * 3

        return (sumofnew - sumOfnums) / 2
        