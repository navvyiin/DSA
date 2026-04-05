class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        if rows == 1:
            return encodedText
        
        n = len(encodedText)
        cols = n // rows
        
        res = []
        
        # Traverse diagonals starting from top row
        for start_col in range(cols):
            i, j = 0, start_col
            while i < rows and j < cols:
                res.append(encodedText[i * cols + j])
                i += 1
                j += 1
        
        # Remove trailing spaces
        return ''.join(res).rstrip()