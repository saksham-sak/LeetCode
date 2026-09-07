class Solution:
    def maxNumberOfFamilies(self, n, reservedSeats):
        rows = {}

        # Store reserved seats using bitmask
        for r, s in reservedSeats:
            rows[r] = rows.get(r, 0) | (1 << s)

        # Rows without reservations can always fit 2 groups
        ans = (n - len(rows)) * 2

        for mask in rows.values():

            # Seats 2,3,4,5
            left = (mask & 0b0000111100) == 0

            # Seats 4,5,6,7
            middle = (mask & 0b0011110000) == 0

            # Seats 6,7,8,9
            right = (mask & 0b1111000000) == 0

            if left and right:
                ans += 2
            elif left or middle or right:
                ans += 1

        return ans