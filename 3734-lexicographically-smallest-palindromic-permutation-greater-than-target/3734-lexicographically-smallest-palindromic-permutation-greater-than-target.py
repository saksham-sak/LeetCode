class Solution(object):
    def lexPalindromicPermutation(self, s, target):
        n = len(s)
        h = n // 2

        # Count characters
        cnt = [0] * 26

        for ch in s:
            cnt[ord(ch) - 97] += 1

        # Check if palindrome is possible
        odd = 0
        middle = ""

        for i in range(26):
            if cnt[i] % 2:
                odd += 1
                middle = chr(i + 97)

            cnt[i] //= 2

        if odd > 1:
            return ""

        # -----------------------------------------
        # 1. Try target's left half exactly
        # -----------------------------------------

        rem = cnt[:]
        left = target[:h]
        possible = True

        for ch in left:
            x = ord(ch) - 97

            if rem[x] == 0:
                possible = False
                break

            rem[x] -= 1

        if possible:
            candidate = left + middle + left[::-1]

            if candidate > target:
                return candidate

        # -----------------------------------------
        # 2. Find smallest LEFT > target[:h]
        # -----------------------------------------

        for i in range(h - 1, -1, -1):

            rem = cnt[:]

            # Try to construct target[:i]
            possible = True

            for j in range(i):
                x = ord(target[j]) - 97

                if rem[x] == 0:
                    possible = False
                    break

                rem[x] -= 1

            if not possible:
                continue

            x = ord(target[i]) - 97

            # Choose smallest character greater than target[i]
            for c in range(x + 1, 26):

                if rem[c] == 0:
                    continue

                rem[c] -= 1

                # Fill remaining positions with smallest chars
                suffix = []

                for k in range(26):
                    suffix.append(chr(k + 97) * rem[k])

                suffix = ''.join(suffix)

                # We only need h-i-1 characters
                suffix = suffix[:h - i - 1]

                new_left = target[:i] + chr(c + 97) + suffix

                candidate = new_left + middle + new_left[::-1]

                if candidate > target:
                    return candidate

                rem[c] += 1

        return ""