
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        int m = queries.size();

        auto lambda = [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        };

        sort(logs.begin(), logs.end(), lambda);

        vector<int> result(m);
        vector<pair<int,int>> indexQueries(m);

        for(int i = 0; i < m; i++) {
            indexQueries[i] = {queries[i], i};
        }

        sort(indexQueries.begin(), indexQueries.end());

        int i = 0, j = 0;

        unordered_map<int,int> mp;

        for(auto [time, idx] : indexQueries) {

            int start = time - x;
            int end = time;

            while(j < logs.size() && logs[j][1] <= end) {
                mp[logs[j][0]]++;
                j++;
            }

            while(i < logs.size() && logs[i][1] < start) {
                mp[logs[i][0]]--;

                if(mp[logs[i][0]] == 0) {
                    mp.erase(logs[i][0]);
                }

                i++;
            }

            result[idx] = n - mp.size();
        }

        return result;
    }
};
