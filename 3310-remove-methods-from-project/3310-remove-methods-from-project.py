class Solution(object):
    def remainingMethods(self, n, k, invocations):
        graph = [[] for _ in range(n)]

        # Build graph
        for a, b in invocations:
            graph[a].append(b)

        # Find suspicious methods
        suspicious = set()
        stack = [k]

        while stack:
            node = stack.pop()

            if node in suspicious:
                continue

            suspicious.add(node)

            for nei in graph[node]:
                if nei not in suspicious:
                    stack.append(nei)

        # Check if an outside method calls a suspicious method
        for a, b in invocations:
            if a not in suspicious and b in suspicious:
                return list(range(n))

        # Remove suspicious methods
        return [i for i in range(n) if i not in suspicious]