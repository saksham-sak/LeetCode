class Solution:
    def smallestPalindrome(self, s, k):
        from collections import Counter

        cnt = Counter(s)

        # First half
        half = []
        for ch in sorted(cnt):
            half += [ch] * (cnt[ch] // 2)

        freq = [0] * 26
        for ch in half:
            freq[ord(ch) - 97] += 1

        # C(n, r), but stop once it reaches limit
        def comb_limit(n, r, limit):
            r = min(r, n - r)
            res = 1

            for i in range(1, r + 1):
                res = res * (n - r + i) // i

                if res >= limit:
                    return limit

            return res

        # Number of distinct permutations, capped at k
        def count_ways():
            ways = 1
            total = 0

            for c in freq:
                if c == 0:
                    continue

                # Add c identical characters
                limit = (k - 1) // ways + 1
                choose = comb_limit(total + c, c, limit)

                ways *= choose

                if ways >= k:
                    return k

                total += c

            return ways

        # Not enough permutations
        if count_ways() < k:
            return ""

        left = []

        # Build kth lexicographical half
        for _ in range(len(half)):

            for c in range(26):
                if freq[c] == 0:
                    continue

                freq[c] -= 1

                ways = count_ways()

                if ways >= k:
                    left.append(chr(c + 97))
                    break

                k -= ways
                freq[c] += 1

        left = ''.join(left)

        # Middle character
        middle = ""
        if len(s) % 2:
            for ch in cnt:
                if cnt[ch] % 2:
                    middle = ch
                    break

        return left + middle + left[::-1]
        