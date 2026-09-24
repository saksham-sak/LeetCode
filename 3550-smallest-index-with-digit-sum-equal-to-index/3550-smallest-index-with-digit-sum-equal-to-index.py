class Solution(object):
    def smallestIndex(self, nums):
        minAll = 10000

        for i in range(len(nums)):
            word = str(nums[i])
            sumEl = 0
            if(len(word) == 1 and nums[i] ==i):
                minAll = min(minAll,i)
            else:
                for ch in word:
                    sumEl += int(ch)

                if(sumEl == i):
                    minAll = min(minAll,i)

        if(minAll != 10000):
            return minAll
        return -1
        


            
            

            

            
        

        


        