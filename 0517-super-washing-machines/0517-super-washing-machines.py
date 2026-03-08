class Solution:
    def findMinMoves(self, machines):
        total = sum(machines)
        n = len(machines)

        if total % n != 0:
            return -1

        target = total // n
        moves = 0
        balance = 0

        for m in machines:
            diff = m - target
            balance += diff
            moves = max(moves, abs(balance), diff)

        return moves