class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> squares;
        squares.reserve(nums.size());

        for (int x : nums) {
            squares.push_back(1LL * x * x);
        }

        sort(squares.begin(), squares.end());

        long long score = 0;
        int n = squares.size();

        // Largest ceil(n/2) squares get a positive sign;
        // the rest get a negative sign.
        for (int i = 0; i < n; ++i) {
            score += (i < n / 2) ? -squares[i] : squares[i];
        }

        return score;
    }
};