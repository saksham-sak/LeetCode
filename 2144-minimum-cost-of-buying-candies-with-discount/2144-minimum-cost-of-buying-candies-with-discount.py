class Solution:
    def minimumCost(self, cost):
        sumOfCost = sum(cost)
        cost.sort(reverse=True)
        for i in range(2,len(cost),3):
            sumOfCost -= cost[i]
        return sumOfCost
          
             