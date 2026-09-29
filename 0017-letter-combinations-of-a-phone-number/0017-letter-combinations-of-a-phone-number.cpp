class Solution {
public:

    vector<string> ans;

    string letters[10] = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(string &digits, int index, string current) {

        // All digits processed
        if (index == digits.length()) {
            ans.push_back(current);
            return;
        }

        int digit = digits[index] - '0';

        for (char ch : letters[digit]) {

            current.push_back(ch);

            solve(digits, index + 1, current);

            // Backtrack
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        solve(digits, 0, "");

        return ans;
    }
};