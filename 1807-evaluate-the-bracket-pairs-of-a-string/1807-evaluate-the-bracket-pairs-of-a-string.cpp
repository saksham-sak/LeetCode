class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string newString;

        unordered_map<string,string> mp;

        for(auto arr : knowledge){
            mp[arr[0]] = arr[1];
        }

        for(int i  = 0;i < s.size(); ){
            if(s[i] == '('){

                string word;
                i++;

                while(s[i] != ')'){
                    word += s[i];
                    i++;
                }
                
                if(mp.find(word) != mp.end()) {
                    newString += mp[word];
                }
                else {
                    newString += '?';
                }

                i++;
            }
            else{
                newString += s[i];
                i++;
            }
        }

        return newString;
    }
};