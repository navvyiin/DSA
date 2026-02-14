class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        result = []

        while columnNumber > 0:
            columnNumber -= 1  # Adjust for 1-based indexing
            remainder = columnNumber % 26
            result.append(chr(ord('A') + remainder))
            columnNumber //= 26

        return "".join(reversed(result))