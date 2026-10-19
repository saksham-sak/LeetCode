
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();

        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        vector<int> result(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int a = num1[i] - '0';
                int b = num2[j] - '0';

                int product = a * b + result[i + j + 1];

                result[i + j + 1] = product % 10;
                result[i + j] += product / 10;
            }
        }

        string ans = "";

        for (int digit : result) {
            if (ans.empty() && digit == 0) {
                continue;
            }

            ans += to_string(digit);
        }

        return ans;
    }
};
