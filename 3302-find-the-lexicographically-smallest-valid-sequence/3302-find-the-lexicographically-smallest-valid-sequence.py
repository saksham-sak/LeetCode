class Solution:
    def validSequence(self, word1, word2):
        m = len(word1)
        n = len(word2)

        # suf[i] tells us the first index of word2
        # that still needs to be matched using word1[i:]
        suf = [0] * (m + 1)

        suf[m] = n

        j = n - 1

        # Build suffix information
        for i in range(m - 1, -1, -1):
            if j >= 0 and word1[i] == word2[j]:
                j -= 1

            suf[i] = j + 1

        ans = []
        j = 0
        changed = False

        # Greedily choose the smallest possible indices
        for i in range(m):

            if word1[i] == word2[j]:
                # Exact match
                ans.append(i)
                j += 1

            elif not changed and suf[i + 1] <= j + 1:
                # Use our one allowed mismatch
                ans.append(i)
                changed = True
                j += 1

            if j == n:
                return ans

        return []