class Solution {
public:
    int maxDepth(string s) {
        int currentCount = 0;
        int maxOpen = 0;

        for(int i = 0;i < s.size();i++){
            if(s[i] == '('){
                currentCount ++;
            }
            else if(s[i] == ')'){
                currentCount --;
            }

            maxOpen = max(maxOpen,currentCount);
            
        }

        return maxOpen;
        
    }
};