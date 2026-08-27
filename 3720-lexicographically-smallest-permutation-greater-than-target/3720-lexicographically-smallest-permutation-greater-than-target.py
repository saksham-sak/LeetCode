class Solution(object):
    def lexGreaterPermutation(self, s, target):
        count = [0] * 26

        for ch in s:
            count[ord(ch) - 97] += 1

        ans = []

        for i in range(len(target)):
            x = ord(target[i]) - 97

            if count[x] > 0:
                ans.append(target[i])
                count[x] -= 1
            else:
                break

        # Start from the first position where
        # we could not continue matching.
        i = len(ans)

        while i >= 0:
            # If we're backtracking over a matched character,
            # put it back into the frequency array.
            if i < len(ans):
                x = ord(ans[i]) - 97
                count[x] += 1
                ans.pop()

            # Find the smallest character greater than target[i]
            if i < len(target):
                x = ord(target[i]) - 97

                for c in range(x + 1, 26):
                    if count[c] > 0:
                        ans.append(chr(c + 97))
                        count[c] -= 1

                        # Append remaining chars in sorted order
                        for j in range(26):
                            ans.append(chr(j + 97) * count[j])

                        return ''.join(ans)

            i -= 1

        return ""
        