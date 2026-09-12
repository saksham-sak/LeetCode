class Solution:
    def maximumWeight(self, intervals):

        n = len(intervals)

        # Keep original index
        arr = []
        for i in range(n):
            l, r, w = intervals[i]
            arr.append([l, r, w, i])

        # Sort by ending position
        arr.sort(key=lambda x: x[1])

        # Store all ending positions
        ends = [x[1] for x in arr]

        # dp[k][i] = best answer using first i intervals
        # while selecting at most k intervals
        dp = [[(0, []) for _ in range(n + 1)] for _ in range(5)]

        import bisect

        for k in range(1, 5):

            for i in range(1, n + 1):

                # Option 1: don't take current interval
                skip = dp[k][i - 1]

                l, r, w, original_index = arr[i - 1]

                # Find last interval whose end < current start
                p = bisect.bisect_left(ends, l, 0, i - 1)

                # Take current interval
                previous_score, previous_indices = dp[k - 1][p]

                take_score = previous_score + w
                take_indices = previous_indices + [original_index]

                # Compare skip vs take
                if take_score > skip[0]:
                    dp[k][i] = (take_score, take_indices)

                elif take_score < skip[0]:
                    dp[k][i] = skip

                else:
                    if sorted(take_indices) < sorted(skip[1]):
                        dp[k][i] = (take_score, take_indices)
                    else:
                        dp[k][i] = skip

        answer = dp[4][n][1]

        return sorted(answer)