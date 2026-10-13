class Solution {
public:
    bool isPerfectSquare(int num) {
       if (num < 0) return false;

    long long left = 0, right = num;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        // Avoid overflow from mid * mid.
        if (mid == 0 || mid <= num / mid) {
            if (mid * mid == num) return true;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false; 
    }
};