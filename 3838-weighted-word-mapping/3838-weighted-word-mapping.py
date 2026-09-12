class Solution:
    def mapWordWeights(self, words, weights):

        result = ""

        for word in words:
            total = 0

            for ch in word:
                total += weights[ord(ch) - ord('a')]

            value = total % 26

            result += chr(ord('z') - value)

        return result