
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find the median
        int mid = (n - 1) / 2;

        nth_element(nums.begin(),
                    nums.begin() + mid,
                    nums.end());

        int median = nums[mid];

        // Step 2: Three-way partition
        int low = 0;
        int i = 0;
        int high = n - 1;

        // Virtual index mapping
        auto index = [&](int k) {
            return (1 + 2 * k) % (n | 1);
        };

        while (i <= high) {
            if (nums[index(i)] > median) {
                swap(nums[index(low)], nums[index(i)]);
                low++;
                i++;
            }
            else if (nums[index(i)] < median) {
                swap(nums[index(i)], nums[index(high)]);
                high--;
            }
            else {
                i++;
            }
        }
    }
};
