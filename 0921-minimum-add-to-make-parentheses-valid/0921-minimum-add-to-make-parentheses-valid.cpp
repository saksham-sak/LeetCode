class Solution {
public:
    int minAddToMakeValid(string s) {
        stack <int> stk;

        int need = 0;

        for(int i = 0;i < s.size();i++){
            if(s[i] == '('){
                stk.push(s[i]);
                need ++;
            }
            else if(s[i] == ')'){
                if(!stk.empty()){
                    stk.pop();
                    need--;
                }else{
                    need ++;
                }
            }
        }

        return need;
    }
};