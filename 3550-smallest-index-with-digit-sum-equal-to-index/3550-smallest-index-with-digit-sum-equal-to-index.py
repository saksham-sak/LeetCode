class Solution(object):
    def smallestIndex(self, nums):
        

        for i in range(len(nums)):
            word = str(nums[i])
            sumEl = 0
            if(len(word) == 1 and nums[i] ==i):
                return i
            else:
                for ch in word:
                    sumEl += int(ch)

                if(sumEl == i):
                    return i

        return -1
        


            
            

            

            
        

        


        