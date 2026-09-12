class Solution:
    def minimumCost(self, cost):
        sumOfCost = sum(cost)
        if (len(cost) < 3):
            return sumOfCost
        else:
            cost.sort(reverse=True)
            for i in range(2,len(cost),3):
                sumOfCost -= cost[i]
            return sumOfCost
          
             