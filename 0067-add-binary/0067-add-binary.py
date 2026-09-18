class Solution(object):
    def addBinary(self, a, b):
        lengthA = len(a) - 1
        lengthB = len(b) - 1
        carry = 0
        arr = []

        while lengthA >= 0 or lengthB >= 0 or carry:
            total = carry
            if lengthA >= 0:
                total += int(a[lengthA])
                lengthA -= 1

            if lengthB >= 0:
                total += int(b[lengthB])
                lengthB -= 1 
            
            arr.append(str(total % 2))
            carry = total // 2


        return "".join(arr[::-1])