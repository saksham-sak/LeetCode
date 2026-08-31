class Solution(object):
    def resultArray(self, nums):
        arr1 = [nums[0]]
        arr2 = [nums[1]]
        count1 = 0
        count2 = 0
        for i in range(2,len(nums)):
            if arr1[count1] > arr2[count2]:
                arr1.append(nums[i])
                count1 += 1
            else:
                arr2.append(nums[i])
                count2 += 1
        return arr1 + arr2

        