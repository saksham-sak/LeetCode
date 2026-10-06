class Solution {
public:
    int minAddToMakeValid(string s) {

        int need = 0;
        int need2 = 0;

        for(int i = 0;i < s.size();i++){
            if(s[i] == '('){
                need ++;
            }
            else if(s[i] == ')'){
                if(need > 0){
                    need--;
                }else{
                    need2 ++;
                }
            }
        }

        return need + need2;
    }
};