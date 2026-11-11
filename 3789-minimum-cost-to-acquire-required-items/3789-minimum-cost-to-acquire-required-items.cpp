class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        if(cost1 + cost2 <= costBoth){
            return (1LL * cost1 * need1) + (1LL * cost2 * need2);
        }
        
        int minRequirment = min(need1,need2);
        long long total = 1LL * minRequirment * costBoth;
         

        need1 -= minRequirment;
        need2 -= minRequirment;

        if(need1 > 0){
                total += 1LL * min(cost1,costBoth) * need1;
        }else if(need2 > 0){

            total += 1LL * min(cost2,costBoth) * need2;
        }

        return total;
        
    }
};