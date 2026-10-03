class Solution {
public:
    bool isPalindrome(string s) {
        string str;

        for(int i = 0; i < s.size(); i++) {
            char ch = tolower(s[i]);

            if((ch >= 'a' && ch <= 'z') ||
               (ch >= '0' && ch <= '9')) {
                str += ch;
            }
        }

        string rev = str;
        reverse(rev.begin(), rev.end());

        return str == rev;
    }
};