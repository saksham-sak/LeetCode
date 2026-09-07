class Solution:
    def isValid(self, s):
        stack = []
        
        for ch in s:
            if ch in "([{":
                stack.append(ch)
            elif not stack or stack[-1] != {')': '(', '}': '{', ']': '['}[ch]:
                return False
            else:
                stack.pop()
        
        return not stack