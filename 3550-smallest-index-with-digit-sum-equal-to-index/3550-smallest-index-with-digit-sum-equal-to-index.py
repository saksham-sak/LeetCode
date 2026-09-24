class Solution(object):
    def smallestIndex(self, nums):
        

        for i in range(len(nums)):
            word = str(nums[i])
            sumEl = 0
            for ch in word:
                sumEl += int(ch)

            if(sumEl == i):
                return i

        return -1
        


            
            

            

            
        

        


        