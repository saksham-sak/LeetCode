class Solution(object):
    def longestCommonPrefix(self, strs):
        longest = ""
        word = ""

        for i in range(min(map(len,strs))):
            word += strs[0][i]
            if all(char.startswith(word) for char in strs):
                longest = word
            else:
                break
        return longest
            
        