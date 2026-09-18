class Solution(object):
    def addBinary(self, a, b):
        stringSum = 0
        stringNum = ""
        for i in range(len(a)):
            if a[i] == "1":
                stringSum += 2**(len(a) - i - 1)
        for i in range(len(b)):
            if b[i] == "1":
                stringSum += 2**(len(b) - i - 1)


        while(stringSum > 0):
            stringNum += str(stringSum % 2)
            stringSum //= 2

        if not stringNum:
            return "0"
        return stringNum[::-1]
    
        


        