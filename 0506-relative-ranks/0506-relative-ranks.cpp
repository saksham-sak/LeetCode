class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size();

        vector<pair<int, int>> arr;

        // Store {score, original index}
        for (int i = 0; i < n; i++) {
            arr.push_back({score[i], i});
        }

        // Sort by score in descending order
        sort(arr.begin(), arr.end(), greater<pair<int, int>>());

        vector<string> ans(n);

        for (int i = 0; i < n; i++) {

            int originalIndex = arr[i].second;

            if (i == 0) {
                ans[originalIndex] = "Gold Medal";
            }
            else if (i == 1) {
                ans[originalIndex] = "Silver Medal";
            }
            else if (i == 2) {
                ans[originalIndex] = "Bronze Medal";
            }
            else {
                ans[originalIndex] = to_string(i + 1);
            }
        }

        return ans;
    }
};