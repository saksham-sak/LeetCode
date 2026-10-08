class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        ans = set()

        left_remove = 0
        right_remove = 0

        # Find minimum removals
        for ch in s:
            if ch == '(':
                left_remove += 1
            elif ch == ')':
                if left_remove > 0:
                    left_remove -= 1
                else:
                    right_remove += 1

        def dfs(i, left, right, balance, path):
            # Invalid branch
            if balance < 0:
                return

            # End of string
            if i == len(s):
                if left == 0 and right == 0 and balance == 0:
                    ans.add(''.join(path))
                return

            ch = s[i]

            if ch == '(':

                # Remove '('
                if left > 0:
                    dfs(i + 1, left - 1, right, balance, path)

                # Keep '('
                path.append(ch)
                dfs(i + 1, left, right, balance + 1, path)
                path.pop()

            elif ch == ')':

                # Remove ')'
                if right > 0:
                    dfs(i + 1, left, right - 1, balance, path)

                # Keep ')' only if valid
                if balance > 0:
                    path.append(ch)
                    dfs(i + 1, left, right, balance - 1, path)
                    path.pop()

            else:
                path.append(ch)
                dfs(i + 1, left, right, balance, path)
                path.pop()

        dfs(0, left_remove, right_remove, 0, [])

        return list(ans)