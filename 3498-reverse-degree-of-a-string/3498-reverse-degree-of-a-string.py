class Solution(object):
    def reverseDegree(self, s):
        sum = 0
        for i in range(len(s)):
            value = 26 +  (97 - ord(s[i]))
            sum += (value * (i + 1))
        
        return sum