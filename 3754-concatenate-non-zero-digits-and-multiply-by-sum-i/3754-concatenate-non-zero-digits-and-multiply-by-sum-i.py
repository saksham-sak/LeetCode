class Solution(object):
    def sumAndMultiply(self, n):
        n = str(n)
        digits = []
        sumNon = 0

        for num in n:
            if num != "0":
                digits.append(num)
                sumNon += int(num)

        if not digits:
            return 0

        return int("".join(digits)) * sumNon
        