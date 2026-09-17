class Solution(object):
    def longestRepeating(self, s, queryCharacters, queryIndices):

        n = len(s)
        tree = [None] * (4 * n)

        # node:
        # (leftChar, rightChar, prefix, suffix, best, length)

        def merge(a, b):
            leftChar = a[0]
            rightChar = b[1]

            prefix = a[2]
            suffix = b[3]

            # If entire left segment has the same character
            # and its character matches the right prefix
            if a[2] == a[5] and a[1] == b[0]:
                prefix = a[5] + b[2]

            # If entire right segment has the same character
            # and its character matches the left suffix
            if b[3] == b[5] and a[1] == b[0]:
                suffix = a[3] + b[5]

            best = max(a[4], b[4])

            # A repeating sequence can cross the boundary
            if a[1] == b[0]:
                best = max(best, a[3] + b[2])

            length = a[5] + b[5]

            return (leftChar, rightChar, prefix, suffix, best, length)

        def build(node, l, r):
            if l == r:
                tree[node] = (s[l], s[l], 1, 1, 1, 1)
                return

            mid = (l + r) // 2

            build(node * 2, l, mid)
            build(node * 2 + 1, mid + 1, r)

            tree[node] = merge(tree[node * 2],
                                tree[node * 2 + 1])

        def update(node, l, r, index, char):
            if l == r:
                tree[node] = (char, char, 1, 1, 1, 1)
                return

            mid = (l + r) // 2

            if index <= mid:
                update(node * 2, l, mid, index, char)
            else:
                update(node * 2 + 1, mid + 1, r, index, char)

            tree[node] = merge(tree[node * 2],
                                tree[node * 2 + 1])

        build(1, 0, n - 1)

        ans = []

        for i in range(len(queryCharacters)):
            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            )

            ans.append(tree[1][4])

        return ans