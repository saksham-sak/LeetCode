class Solution(object):
    def firstStableIndex(self, nums, k):
        if len(nums) == 1:
            return 0
        for i in range(len(nums)):
            maxEle = max(nums[:i+1])
            minEle = min(nums[i:])
            stability = maxEle - minEle
            if stability <= k:
                return i

        return -1
        