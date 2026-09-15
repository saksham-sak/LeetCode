class Solution(object):
    def lengthOfLastWord(self, s):
        s = s.strip()
        arr = list(s.split(" "))
        return len(arr[-1])
        