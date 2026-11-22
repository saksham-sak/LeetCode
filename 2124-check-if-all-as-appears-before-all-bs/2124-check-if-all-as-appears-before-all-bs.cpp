class Solution {
public:
    bool checkString(string s) {

        int n = s.size();
        

        for(int i = 0;i < n;i++){
            if(s[i] == 'b'){
                for(int j = i;j < n;j++){
                    if(s[j] == 'a'){
                        return false;
                    }

                    i++;
                }
            }
        }



        return true;
    }
};