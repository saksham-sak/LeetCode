class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(), nums1.end());
        vector<int> result;

        for (auto k : s) {
            if (count(nums2.begin(), nums2.end(), k)) {
                result.push_back(k);
            }
        }

        return result;
    }
};