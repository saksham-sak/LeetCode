
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        deque<pair<int, int>> dq;

        long long sumMax = 0;
        long long sumNums = 0;
        long long ans = 0;

        int right = n - 1;

        for (int left = n - 1; left >= 0; left--) {
            int x = nums[left];
            int cnt = 1;

            while (!dq.empty() && dq.front().first <= x) {
                sumMax -= 1LL * dq.front().first * dq.front().second;
                cnt += dq.front().second;
                dq.pop_front();
            }

            dq.push_front({x, cnt});
            sumMax += 1LL * x * cnt;
            sumNums += x;

            while (sumMax - sumNums > k) {
                sumNums -= nums[right];

                sumMax -= dq.back().first;

                dq.back().second--;

                if (dq.back().second == 0) {
                    dq.pop_back();
                }

                right--;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};
