class Solution(object):
    def isPalindrome(self, x):
        x = str(x)
        n = x[::-1]
        return True if x == n else False