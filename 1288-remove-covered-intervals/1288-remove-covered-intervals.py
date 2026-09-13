class Solution(object):
    def removeCoveredIntervals(self, intervals):
        intervals.sort(key=lambda x: (x[0], -x[1]))

        count = 0
        maxEnd = 0

        for start, end in intervals:
            if end <= maxEnd:
                count += 1
            else:
                maxEnd = end

        return len(intervals) - count
                
        