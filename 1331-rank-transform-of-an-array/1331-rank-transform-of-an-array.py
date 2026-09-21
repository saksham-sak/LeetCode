class Solution(object):
    def arrayRankTransform(self, arr):
        sorted_arr = sorted(arr)

        rank = {}
        r = 1

        for x in sorted_arr:
            if x not in rank:
                rank[x] = r
                r += 1

        for i in range(len(arr)):
            arr[i] = rank[arr[i]]

        return arr