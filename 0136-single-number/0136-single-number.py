class Solution(object):
    def singleNumber(self, nums):
        i = 0
        j = i + 1

        while(j < len(nums)):
            if(nums[i] == nums[j]):
                del nums[j]
                del nums[i]
                j = i + 1
            else:
                j += 1

        return nums[i]

        
        