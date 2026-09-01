from collections import deque

class Solution(object):
    def minMoves(self, classroom, energy):
        m = len(classroom)
        n = len(classroom[0])

        litter_id = {}
        start = 0
        k = 0

        # Find start and assign each litter a bit
        for r in range(m):
            for c in range(n):
                if classroom[r][c] == 'S':
                    start = r * n + c

                elif classroom[r][c] == 'L':
                    litter_id[r * n + c] = k
                    k += 1

        full_mask = (1 << k) - 1

        # State:
        # (position, remaining_energy, mask, moves)
        q = deque()
        q.append((start, energy, 0, 0))

        # best[(position, mask)] = maximum energy reached
        best = {}
        best[(start, 0)] = energy

        directions = ((1, 0), (-1, 0), (0, 1), (0, -1))

        while q:
            pos, e, mask, moves = q.popleft()

            r = pos // n
            c = pos % n

            # All litter collected
            if mask == full_mask:
                return moves

            # No energy means we cannot move
            if e == 0:
                continue

            for dr, dc in directions:
                nr = r + dr
                nc = c + dc

                if nr < 0 or nr >= m or nc < 0 or nc >= n:
                    continue

                if classroom[nr][nc] == 'X':
                    continue

                new_pos = nr * n + nc
                new_energy = e - 1
                new_mask = mask

                # Collect litter
                if new_pos in litter_id:
                    new_mask |= 1 << litter_id[new_pos]

                # Reset energy
                if classroom[nr][nc] == 'R':
                    new_energy = energy

                key = (new_pos, new_mask)

                # Already reached this state with more/equal energy
                if key in best and best[key] >= new_energy:
                    continue

                # This state is better
                best[key] = new_energy

                q.append((
                    new_pos,
                    new_energy,
                    new_mask,
                    moves + 1
                ))

        return -1    
        