class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        // Edge case: if s1 is longer than s2, a permutation is impossible
        if (n1 > n2) return false;

        // Create a frequency array of size 26 for lowercase letters (a-z), initialized to 0
        vector<int> count(26, 0);
        
        // Populate the frequency array with counts of each character in s1
        for (char c : s1) {
            count[c - 'a']++;
        }

        // Initialize sliding window pointers (l for left, r for right)
        int l = 0, r = 0;
        
        // 'required' tracks how many total characters of s1 we still need to match
        int required = n1; 

        // Expand the window by moving the right pointer across s2
        while (r < n2) {
            // 1. If the current character is needed (count > 0), reduce our 'required' count
            if (count[s2[r] - 'a'] > 0) {
                required--;
            }
            
            // Decrement the count in our array (can drop below 0 if we have extra characters)
            count[s2[r] - 'a']--;
            
            // Move the right pointer forward to expand the window
            r++;

            // If required hits 0, all characters of s1 are found inside the current window!
            if (required == 0) return true;

            // 2. Maintain a fixed window size equal to n1:
            // If the window length reaches n1, we must shrink from the left before expanding further.
            if (r - l == n1) {
                // If the character about to leave was a required one (count >= 0), restore 'required'
                if (count[s2[l] - 'a'] >= 0) {
                    required++;
                }
                
                // Give the character back to the frequency array
                count[s2[l] - 'a']++;
                
                // Shift the left boundary forward to shrink the window
                l++;
            }
        }

        // If the loop finishes without hitting required == 0, no permutation exists
        return false;
    }
};