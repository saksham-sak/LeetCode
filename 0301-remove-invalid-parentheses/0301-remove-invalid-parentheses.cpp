class Solution {
public:

    unordered_set<string> ans;

    void solve(string& s, int index,
               int leftRemove, int rightRemove,
               int balance, string path) {

        // Finished processing string
        if(index == s.size()) {

            if(leftRemove == 0 &&
               rightRemove == 0 &&
               balance == 0) {

                ans.insert(path);
            }

            return;
        }

        char ch = s[index];

        // Case 1: '('
        if(ch == '(') {

            // Remove '('
            if(leftRemove > 0) {
                solve(s, index + 1,
                      leftRemove - 1,
                      rightRemove,
                      balance,
                      path);
            }

            // Keep '('
            solve(s, index + 1,
                  leftRemove,
                  rightRemove,
                  balance + 1,
                  path + ch);
        }

        // Case 2: ')'
        else if(ch == ')') {

            // Remove ')'
            if(rightRemove > 0) {
                solve(s, index + 1,
                      leftRemove,
                      rightRemove - 1,
                      balance,
                      path);
            }

            // Keep ')' only if there is '(' available
            if(balance > 0) {
                solve(s, index + 1,
                      leftRemove,
                      rightRemove,
                      balance - 1,
                      path + ch);
            }
        }

        // Case 3: letter
        else {

            solve(s, index + 1,
                  leftRemove,
                  rightRemove,
                  balance,
                  path + ch);
        }
    }


    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum removals
        for(char ch : s) {

            if(ch == '(') {
                leftRemove++;
            }

            else if(ch == ')') {

                if(leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        solve(s, 0,
              leftRemove,
              rightRemove,
              0,
              "");

        return vector<string>(ans.begin(), ans.end());
    }
};