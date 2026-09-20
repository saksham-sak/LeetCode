class Solution(object):
    def reverseDegree(self, s):
        sum = 0
        for i in range(len(s)):
            sum += ((26 +  (97 - ord(s[i]))) * (i + 1))
        
        return sum