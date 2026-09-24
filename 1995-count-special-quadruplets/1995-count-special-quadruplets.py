class Solution(object):
    def countQuadruplets(self, nums):
        count = 0
        for i in range(len(nums)):
            for j in range(i+ 1,len(nums)):
                for k in range(j+1,len(nums)):
                    for d in range(k+1,len(nums)):
                        if nums[i] + nums[j] + nums[k] == nums[d]:
                            count += 1
        return count                  
        