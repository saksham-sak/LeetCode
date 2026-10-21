class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";

        for(int i = n - 1;i >= 0;i--){
            string word = "";
            while(i >= 0 && s[i] != ' '){
                word += s[i];
                i--;
            }

            reverse(word.begin(),word.end());

            if(word.size() > 0){
                ans += " " + word;
            }
        }

        return ans.substr(1);
    }
};