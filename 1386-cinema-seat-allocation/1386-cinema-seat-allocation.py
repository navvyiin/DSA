class Solution:
    def maxNumberOfFamilies(self, n, reservedSeats):
        rows = {}

        # Only rows with reserved seats need to be checked.
        for r, s in reservedSeats:
            rows[r] = rows.get(r, 0) | (1 << s)

        # Every completely empty row can fit 2 groups.
        ans = (n - len(rows)) * 2

        for mask in rows.values():
            count = 0

            # Seats 2,3,4,5
            if not (mask & (1 << 2 | 1 << 3 | 1 << 4 | 1 << 5)):
                count += 1

            # Seats 6,7,8,9
            if not (mask & (1 << 6 | 1 << 7 | 1 << 8 | 1 << 9)):
                count += 1

            # If neither outer block is available,
            # check the middle block 4,5,6,7.
            if count == 0:
                if not (mask & (1 << 4 | 1 << 5 | 1 << 6 | 1 << 7)):
                    count = 1

            ans += count

        return ans