class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int count[121] = {0};
        for (int a : ages) count[a]++;

        int total = 0;
        for (int a = 1; a <= 120; a++) {
            if (count[a] == 0) continue;
            for (int b = 1; b <= a; b++) {
                if (count[b] == 0) continue;
                if (b <= 0.5 * a + 7) continue;
                total += count[a] * count[b];
                if (a == b) total -= count[a];
            }
        }
        return total;
    }
};